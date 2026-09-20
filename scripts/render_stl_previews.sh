#!/usr/bin/env bash
set -euo pipefail

STL_ROOT="${1:-site/downloads/stl/build}"
PREVIEW_ROOT="${2:-site/assets/stl-previews}"
MANIFEST="${3:-site/assets/stl-previews/manifest.json}"

command -v openscad >/dev/null
command -v xvfb-run >/dev/null

mkdir -p "$PREVIEW_ROOT"
tmpdir="$(mktemp -d)"
trap 'rm -rf "$tmpdir"' EXIT

printf '[\n' > "$MANIFEST"
first=1

while IFS= read -r -d '' stl; do
  rel="${stl#"$STL_ROOT"/}"
  group="$(dirname "$rel")"
  file="$(basename "$rel")"
  stem="${file%.stl}"

  outdir="$PREVIEW_ROOT/$group"
  mkdir -p "$outdir"
  png="$outdir/$stem.png"
  webp="$outdir/$stem.webp"
  wrapper="$tmpdir/render.scad"

  printf 'import(%q);\n' "$(realpath "$stl")" > "$wrapper"

  xvfb-run -a openscad \
    --imgsize=1200,900 \
    --autocenter \
    --viewall \
    --projection=p \
    --colorscheme="Tomorrow Night" \
    --camera=0,0,0,58,0,35,0 \
    -o "$png" "$wrapper"

  if command -v cwebp >/dev/null; then
    cwebp -quiet -q 86 "$png" -o "$webp"
  else
    cp "$png" "$webp"
  fi

  test -s "$webp"

  [ "$first" -eq 1 ] || printf ',\n' >> "$MANIFEST"
  first=0
  python3 - "$group" "$stem" "$rel" "$webp" >> "$MANIFEST" <<'PY'
import json, sys
group, stem, rel, webp = sys.argv[1:]
print("  " + json.dumps({
  "group": group,
  "name": stem,
  "stl": "downloads/stl/build/" + rel.replace("\\","/"),
  "preview": webp.replace("site/","",1).replace("\\","/")
}, ensure_ascii=False), end="")
PY
done < <(find "$STL_ROOT" -type f -name '*.stl' -size +1024c -print0 | sort -z)

printf '\n]\n' >> "$MANIFEST"
python3 -m json.tool "$MANIFEST" >/dev/null

count="$(python3 - <<PY
import json
print(len(json.load(open("$MANIFEST", encoding="utf-8"))))
PY
)"
echo "Generated $count STL previews and manifest: $MANIFEST"
test "$count" -gt 0
