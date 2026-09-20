# 135er Universal Helicopter Controller

Open-source, cross-platform helicopter flight control system for Microsoft Flight Simulator, X-Plane and other simulators.

## Goals

- Hall-effect sensing for every analog control axis
- FDM-first mechanical design with low-support / support-free parts wherever practical
- Standard USB HID operation without mandatory proprietary drivers
- Cross-platform use on Windows, Linux and macOS
- Modular Cyclic, Collective and Anti-Torque Pedals
- Replaceable grips and sensor mounts
- PETG-first printable design with stronger-material options where useful
- RP2350-based main controller architecture

## V1 Modules

- Cyclic: pitch + roll
- Collective: collective + twist throttle
- Pedals: yaw + optional toe brakes

## Target analog axes

1. Cyclic pitch
2. Cyclic roll
3. Collective
4. Twist throttle
5. Anti-torque pedals
6. Left toe brake
7. Right toe brake

## Mechanical design rules

- Parts must fit within a 256 x 256 mm FDM build area
- Minimize supports and long bridges
- Standard walls: 2.4-3.2 mm
- High-load areas: 4-6 mm
- Prefer M3/M4 fasteners and standard steel shafts
- Use bearings for precision pivots instead of printed bearing surfaces
- Separate replaceable sensor mounts from structural parts
- Target 0.25-0.35 mm running clearance for PETG moving interfaces

## Electronics architecture

- RP2350 main controller
- USB-C
- Standard USB HID joystick interfaces
- Internal 16-bit processing for analog axes
- Hall / magnetic angle sensors
- Modular expansion via CAN or RS485 planned

## Repository structure

```text
cad/            Printable mechanical modules and source CAD
firmware/       RP2350 USB-HID firmware
hardware/       Electronics and mechanical documentation
docs/           Design notes, assembly and calibration
profiles/       Simulator / aircraft profiles
tools/          Calibration and development utilities
```

## Status

**V0.1 - architecture and mechanical baseline**

First implementation target: **Cyclic V1**.

## Licensing

Software: MIT.
Hardware/CAD license will be finalized before the first production-ready CAD release.
