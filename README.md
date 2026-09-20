# 135er Universal Helicopter Controller

Open-source, cross-platform helicopter flight controls for Microsoft Flight Simulator, X-Plane and other simulators.

## Current branch: V1.1 engineering / RC2 candidate

The original V1 RC1 proved the basic architecture and automated build flow. V1.1 hardens the design before physical validation.

Current scope:

- Cyclic: pitch + roll
- Collective: collective + twist throttle
- Pedals: anti-torque yaw + independent left/right toe brakes
- Seven contactless Hall-based analog axes
- Raspberry Pi Pico 2 / RP2350 main controller
- MCP3208 external SPI ADC
- Standard USB HID joystick
- USB CDC diagnostic/configuration console
- 32 HID button bits + 8-way hat
- eight direct debounced button inputs in the first wiring revision
- persistent calibration in flash
- FDM-first PETG mechanical design
- automated STL, host-test and firmware builds

> No V1.x build is physically validated yet. CI success proves that the firmware compiles and CAD renders; it does not prove fit, strength, ergonomics or flight quality.

## Architecture

```text
7 x AS5600 magnetic angle sensors (analog OUT)
                 |
                 v
        MCP3208 8-channel SPI ADC
                 |
                 v
        Raspberry Pi Pico 2 / RP2350
           |                 |
           v                 v
       USB HID          USB CDC console
           |
   Windows / Linux / macOS
           |
      MSFS / X-Plane
```

Using analog output avoids the fixed-I2C-address problem that appears when several AS5600 modules share one bus.

## Axes

1. Cyclic Roll
2. Cyclic Pitch
3. Collective
4. Twist Throttle
5. Anti-Torque Pedals
6. Left Toe Brake
7. Right Toe Brake

## Firmware V1.1 improvements

- real persistent calibration with CRC validation
- first-sample filter seeding; no artificial startup sweep
- configurable filter, inversion, center deadzone and bipolar expo
- direct button and hat input support
- unique USB serial number per Pico 2
- CDC console for calibration and diagnostics
- 1 ms scheduler with overrun counter
- MCP3208 acquisition budget corrected from the original RC1 implementation
- host regression tests for axis math

See `docs/FIRMWARE_V1_1.md`.

## Mechanical V1.1 improvements

- real toe-brake printable modules
- dedicated collective friction adjuster
- modular split cyclic grip with switch openings
- dedicated electronics tray and ventilated lid
- steel primary shafts and bearings remain mandatory
- replaceable Hall sensor carriers and magnet interfaces

## Repository

```text
cad/
  cyclic/
  collective/
  pedals/
  electronics/
  validation/
firmware/
hardware/
docs/
profiles/
site/
.github/workflows/
```

## FDM rules

- target printer envelope: 256 x 256 x 256 mm
- PETG baseline; ASA optional after fit validation
- support-free geometry wherever practical
- steel shafts for primary pivots
- bearings for precision rotation
- M3/M4/M5/M6 standard hardware
- fit-critical dimensions are frozen only after coupon testing

## Print-first workflow

1. Print the validation plate / fit coupons.
2. Record best bearing, shaft, tube, magnet and fastener fits.
3. Freeze dimensional compensation for the actual printer/filament.
4. Print and assemble Cyclic first.
5. Validate Hall alignment and controls.
6. Continue with Collective.
7. Continue with Pedals and toe brakes.
8. Install electronics enclosure and harness.
9. Calibrate through the CDC console.
10. Test MSFS and X-Plane.
11. Only after the validation checklist passes may a release be labeled **VALIDATED**.

## Research basis

The project has been compared against FreeJoy, OpenFFBoard, several open helicopter-collective projects and 3D-printable Hall joystick projects. Adopted ideas and license boundaries are documented in `docs/RESEARCH_NOTES.md`.

No GPL source code from FreeJoy is copied into this MIT firmware.

## Documentation

- `docs/ASSEMBLY_V1.md`
- `docs/FIRMWARE_V1_1.md`
- `docs/PRINTING.md`
- `docs/CALIBRATION.md`
- `docs/VALIDATION_CHECKLIST.md`
- `docs/RC1_STATUS.md`
- `docs/RESEARCH_NOTES.md`
- `hardware/BOM_V1_RC1.md`

## License

Software: MIT.

Hardware/CAD source remains open and the final dedicated hardware-license file will be frozen before the first physically validated release.
