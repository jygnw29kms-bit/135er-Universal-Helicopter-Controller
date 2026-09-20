# Firmware V1.1

Target: Raspberry Pi Pico 2 / RP2350 using Pico SDK and TinyUSB.

## Inputs

Analog chain:

```text
7 x AS5600-class Hall angle sensors (analog OUT)
-> MCP3208
-> RP2350
```

Axis order:
1. Cyclic Roll
2. Cyclic Pitch
3. Collective
4. Twist Throttle
5. Pedals
6. Left Toe Brake
7. Right Toe Brake

Digital V1.1:
- GPIO2..9: buttons 1..8, active low
- GPIO10..13: four-way hat, active low
- five-sample debounce

The HID report still reserves 32 button bits for future expansion.

## USB

Composite USB device:
- HID joystick
- CDC serial configuration/diagnostics

The HID interface exposes seven 16-bit logical axes, 32 buttons and one 8-way hat.

## Calibration

Calibration is stored in the last flash sector with a version field and CRC.

Use the CDC console:

```text
help
status
cal show
cal set roll 800 8100 15400
deadzone roll 120
filter roll 2
expo roll 10
invert roll 0
save
```

See `docs/FIRMWARE_V1_1.md` and `docs/CALIBRATION.md`.

## Timing

MCP3208 SPI runs at 1 MHz. Four readings are accumulated per axis per frame. The main report schedule targets 1 ms and counts overruns for validation.

The four-sample accumulation uses a 0..16380 numeric calibration domain; it must not be described as guaranteed 14-bit ADC ENOB.

## Build

```bash
export PICO_SDK_PATH=/path/to/pico-sdk
cmake -S firmware -B build -DPICO_BOARD=pico2
cmake --build build -j
```

CI also compiles and runs host-side regression tests for axis processing.
