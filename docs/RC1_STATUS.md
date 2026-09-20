# V1 RC1 Status

## Completed
- Cross-platform standard USB HID architecture
- RP2350/Pico 2 firmware source
- Seven Hall-axis input architecture
- MCP3208 SPI ADC integration
- 16-bit logical HID axes
- Cyclic CAD source
- Collective CAD source
- Pedal CAD source
- FDM-first PETG print guidance
- BOM
- Assembly guide
- MSFS and X-Plane profile guidance
- Automated STL generation workflow
- Automated firmware build workflow

## Automated validation
- CAD GitHub Actions build: **PASS**
- RP2350/Pico 2 firmware GitHub Actions build: **PASS**
- 16/16 locally rendered STL meshes: **watertight/manifold**
- Largest part: pedal base, 240 x 180 x 54 mm
- All current production parts fit the 256 x 256 x 256 mm design envelope

## Pending physical validation
V1 RC1 is a buildable design release candidate, not a production-validated hardware release.

An actual printed assembly must still pass `VALIDATION_CHECKLIST.md`, including bearing/shaft fit, mechanical travel, sensor alignment, measured Hall calibration values and simulator tests.

Only after those checks should the project be tagged **VALIDATED**.
