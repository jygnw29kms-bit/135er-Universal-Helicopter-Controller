# BOM V1.1 / RC2 candidate

## Electronics
- 1x Raspberry Pi Pico 2 (RP2350)
- 1x MCP3208 8-channel 12-bit SPI ADC
- 7x AS5600 magnetic angle sensor modules with analog OUT available
- 7x compatible diametrically magnetized magnets, nominal 6 mm diameter
- 1x USB data cable
- 8x momentary switches minimum for the first direct-button build
- 1x four-way hat mechanism or four momentary switches
- JST-XH or equivalent locking connectors for serviceable module wiring
- 3.3 V sensor rail and common ground distribution

### Recommended signal-integrity parts
For custom/bare sensor carriers rather than finished modules:
- local ceramic decoupling close to each sensor
- MCP3208 supply/reference decoupling close to the ADC
- small bulk capacitor on the sensor rail
- keep analog sensor runs away from USB and fast digital wiring where practical
- join analog/digital grounds cleanly and avoid high-current return paths through sensor ground

Verify what capacitors are already populated on purchased AS5600 breakout boards before duplicating them.

## Cyclic
- 4x 608-2RS bearings minimum
- 2x 8 mm steel shafts
- 1x 20-22 mm OD aluminium tube, about 500 mm
- M3 hardware for sensor/switch modules
- M4 structural screws, washers and lock nuts
- optional light extension springs
- switches for PTT / force-trim / spare functions

## Collective
- bearings to suit final 10 mm pivot arrangement
- 1x 10 mm steel shaft
- 1x 20-22 mm OD aluminium tube
- M4/M5 fasteners
- friction washers/material plus M5 friction-adjuster hardware
- optional rotary encoder / additional switches for aircraft-specific controls

## Pedals
- bearings to suit final 10 mm center pivot
- 1x 10 mm steel center shaft
- 2x 6 mm toe-brake pivot shafts
- M5/M6 structural fasteners
- return springs for left/right toe brake
- three Hall sensor mounts total: yaw + two toe-brake axes

## Printing
- PETG baseline for V1
- ASA optional after dimensional validation
- 0.4 mm nozzle
- 0.20 mm layer height
- 4 perimeters on structural parts
- 30-40% infill baseline
- local reinforcement around pivots/lever/rocker as required

No printed part is intended to replace the primary steel pivot shafts.
