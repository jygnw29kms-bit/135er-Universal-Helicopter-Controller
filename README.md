# 135er Universal Helicopter Controller

Open-source, cross-platform helicopter flight controls for Microsoft Flight Simulator, X-Plane and other simulators.

## V1 RC1

The project now contains a complete **design release candidate** for:

- Cyclic: pitch + roll
- Collective: collective + twist throttle
- Pedals: anti-torque yaw + optional toe-brake channels
- Seven Hall-based analog axes
- RP2350 / Raspberry Pi Pico 2 main controller
- Standard USB HID output
- FDM-first PETG mechanical design
- Automated STL and firmware builds via GitHub Actions

> RC1 means the design is complete enough to build and test. It is **not yet physically validated**. Final production validation requires an actual printed assembly, measured Hall endpoints and simulator testing.

## Electronics

The V1 architecture uses:

```text
7 x AS5600 magnetic angle sensors (analog OUT)
                 |
                 v
        MCP3208 8-channel SPI ADC
                 |
                 v
        Raspberry Pi Pico 2 / RP2350
                 |
                 v
          Standard USB HID
                 |
          Windows / Linux / macOS
                 |
           MSFS / X-Plane
```

Using the Hall sensors in analog-output mode avoids I2C address conflicts while keeping every control axis contactless.

## Logical axes

1. Cyclic Roll
2. Cyclic Pitch
3. Collective
4. Twist Throttle
5. Anti-Torque Pedals
6. Left Toe Brake
7. Right Toe Brake

The HID descriptor also reserves 32 buttons and one hat switch.

## Repository

```text
cad/
  common.scad
  cyclic/
  collective/
  pedals/
firmware/
hardware/
docs/
profiles/
.github/workflows/
```

## FDM design rules

- Designed around a 256 x 256 mm class build plate
- PETG baseline
- Support-free geometry wherever practical
- Steel shafts for main pivots
- Bearings for precision rotation
- M3/M4/M5/M6 standardized hardware
- Replaceable Hall sensor carriers
- No printed main pivot shafts
- 0.25-0.35 mm nominal moving clearance

## Automated builds

GitHub Actions generates:

- STL bundle from all OpenSCAD sources
- RP2350 UF2/ELF firmware build

## Build order

1. Print Cyclic and verify gimbal movement.
2. Align Hall sensors and magnets.
3. Assemble Collective.
4. Assemble Pedals.
5. Wire all seven channels to the MCP3208.
6. Flash Pico 2 firmware.
7. Record real min/center/max sensor values.
8. Complete `docs/VALIDATION_CHECKLIST.md`.
9. Map axes in MSFS or X-Plane.

## Documentation

- `docs/ASSEMBLY_V1.md`
- `docs/PRINTING.md`
- `docs/CALIBRATION.md`
- `docs/VALIDATION_CHECKLIST.md`
- `docs/RC1_STATUS.md`
- `hardware/BOM_V1_RC1.md`

## Current validation state

All 16 current printable CAD parts were rendered locally with OpenSCAD without parser/render failures.

That confirms the CAD sources generate STL geometry. It does **not** yet prove dimensional fit, bearing preload, structural strength or sensor alignment on a physical print.

## License

Software: MIT.

Hardware/CAD licensing will be finalized before a production-validated hardware release.
