# V1.1 / RC2 engineering status

The project has moved beyond the original RC1 implementation. RC1 remains a useful historical milestone, but the main branch now contains the V1.1 engineering hardening work intended to become RC2.

## Implemented

- RP2350 / Pico 2 target
- seven Hall-based analog axes
- MCP3208 SPI acquisition
- standard USB HID joystick
- composite USB CDC diagnostics/configuration
- 32 HID button bits plus 8-way hat
- eight direct debounced button inputs
- persistent CRC-protected calibration in flash
- configurable inversion, filtering, deadzone and bipolar expo
- unique USB serial number
- acquisition overrun diagnostics
- host-side axis regression tests
- cyclic, collective and pedal CAD
- actual toe-brake CAD modules
- collective friction adjuster
- split cyclic grip prototype
- Pico/MCP3208 electronics enclosure
- automated CAD and firmware builds

## Not physically validated

No V1.x release is allowed to be called VALIDATED until a real printed controller has passed:
- fit coupons
- bearing/shaft/tube fit
- mechanical travel and hard-stop tests
- Hall alignment
- measured calibration
- USB enumeration
- button/hat tests
- sustained overrun check
- MSFS/X-Plane mapping
- extended flight test

## Remaining before RC2 freeze

- print validation plate
- freeze P2S/PETG dimensional compensation
- confirm toe-brake pivot geometry on a physical pedal
- confirm cyclic grip ergonomics and switch selection
- confirm collective friction material and preload
- create final wiring harness drawing
- evaluate dedicated PCB after breadboard/prototype validation
