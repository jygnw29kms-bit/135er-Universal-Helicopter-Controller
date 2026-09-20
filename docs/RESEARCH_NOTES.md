# Design research and adopted patterns

This document records concepts reviewed from other open-source simulator-control projects and what was deliberately adopted or rejected.

## Reviewed projects

### FreeJoy
Useful concepts:
- per-axis calibration
- configurable filtering
- inversion/deadzone/curve processing
- buttons, hats and encoders as independent input sources
- MCP3208 support as an external ADC

License note: FreeJoy is GPL-3.0. No FreeJoy source code is copied into this MIT-licensed firmware. Only general architectural ideas are used.

### OpenFFBoard
Useful concepts:
- modular input-source architecture
- separation of input acquisition from USB report generation
- runtime configuration/diagnostics
- CAN as a sensible future expansion path

Not adopted for V1:
- force-feedback motor stack
- HID PID/FFB implementation

### JRNitre/JoystickFreeJoy
Useful concepts:
- 3D-printable modular gimbal construction
- precision bearings and steel hardware instead of printed primary shafts
- contactless high-resolution magnetic sensing
- replaceable sensor/magnet geometry

### KalebClark/HeliCollective
Useful concepts:
- dedicated collective friction hardware
- separate handle/hat components
- serviceable modular parts rather than one monolithic print

### JoePrimo/Helicopter-Collective
Useful concepts:
- button matrix / encoder handling
- practical simulator-oriented grip controls

### geoff-coppertop/helicopter-collective
Useful concepts:
- RP2350 as target MCU
- separation of hardware-independent processing logic from peripheral code
- host-side tests for filtering and processing logic
- diagnostics/status interface

## Adopted for 135er V1.1

- central hardware configuration file
- first-sample filter seeding to remove startup transients
- configurable per-axis filter strength
- center deadzone with range re-scaling
- optional bipolar expo
- persistent calibration in Pico 2 flash
- CDC serial configuration/diagnostic console
- direct debounced buttons plus 8-way hat
- unique USB serial number derived from the Pico board ID
- acquisition timing corrected for the real MCP3208 transaction budget
- loop-overrun counter
- host regression tests for axis processing
- toe-brake mechanical modules
- collective friction adjuster
- split cyclic grip with switch openings
- dedicated electronics tray and lid

## Deliberately deferred

- FFB / active cyclic
- force trim motors/clutches
- CAN/RS485 remote modules
- 32-button shift-register expansion
- graphical desktop configurator
- dedicated controller PCB
- automatic calibration wizard

These belong to later revisions after the passive V1 hardware has been physically validated.
