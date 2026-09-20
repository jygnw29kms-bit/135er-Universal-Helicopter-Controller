# CAD Render Validation - V1 RC1

Local validation was performed by rendering every production OpenSCAD source to STL and checking the resulting meshes.

## Result

- 16/16 production parts rendered successfully.
- 16/16 meshes reported watertight/manifold.
- Every individual part fits inside a 256 x 256 x 256 mm build volume.

| Part | Bounding box mm |
|---|---:|
| Cyclic base | 220 x 180 x 21 |
| Cyclic outer gimbal | 124 x 104 x 18 |
| Cyclic inner gimbal | 86 x 68 x 34 |
| Cyclic stick clamp | 54 x 38 x 46 |
| Cyclic sensor mount | 50 x 42 x 8 |
| Cyclic magnet hub | 18 x 18 x 10 |
| Collective base | 190 x 90 x 50.15 |
| Collective lever root | 89 x 50 x 28 |
| Collective throttle grip left | 145 x 30 x 42 |
| Collective throttle grip right | 145 x 30 x 42 |
| Collective sensor mount | 42 x 42 x 4 |
| Pedal base | 240 x 180 x 54 |
| Pedal rocker | 210 x 48 x 24 |
| Pedal left | 82 x 150 x 12 |
| Pedal right | 82 x 150 x 12 |
| Pedal sensor mount | 42 x 42 x 4 |

This verifies that the source produces closed printable meshes and meets the target envelope. It does not replace a real print, dimensional fit check or strength test.
