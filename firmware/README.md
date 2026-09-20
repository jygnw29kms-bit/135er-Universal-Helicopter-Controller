# Firmware V1 RC1

Target: Raspberry Pi Pico 2 / RP2350 using the Pico SDK and TinyUSB.

Input chain: 7 x AS5600-class magnetic Hall angle sensors in analog-output mode -> MCP3208 8-channel SPI ADC -> RP2350.

Axis order:
1. Cyclic Roll
2. Cyclic Pitch
3. Collective
4. Twist Throttle
5. Pedals
6. Left Toe Brake
7. Right Toe Brake

Build:

```bash
export PICO_SDK_PATH=/path/to/pico-sdk
cmake -S firmware -B build -DPICO_BOARD=pico2
cmake --build build -j
```

The Pico SDK selects RP2350 automatically for `PICO_BOARD=pico2`.

The HID report exposes seven 16-bit logical axes, 32 buttons and one hat. RC1 intentionally uses safe default calibration values until physical endpoint measurements exist; physical validation is required before calling the design production-validated.
