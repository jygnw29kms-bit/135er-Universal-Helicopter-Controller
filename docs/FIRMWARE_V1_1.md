# Firmware V1.1 engineering notes

## Signal path

```
7x AS5600 analog OUT
      |
      v
MCP3208 (SPI, 1 MHz)
      |
      v
4 samples/channel per frame
      |
      v
per-axis IIR filter
      |
      v
calibration + deadzone + optional expo
      |
      v
16-bit logical HID axis
```

The MCP3208 remains a 12-bit ADC. Four samples are accumulated into the existing 0..16380 calibration domain. Do not describe this as a guaranteed 14-bit ENOB measurement.

## 1 ms scheduling

The earlier 16-sample/channel implementation could not meet a true 1 ms seven-axis cycle at the configured SPI speed. V1.1 uses four samples per channel at 1 MHz and tracks missed scheduling windows with `loop_overruns`.

## USB

The controller enumerates as a composite device:
- standard joystick HID
- CDC serial configuration console

HID exposes:
- 7 axes
- 32 button bits
- one 8-way hat

V1.1 directly wires eight debounced buttons. The remaining HID button bits are reserved for future matrix/shift-register expansion.

## Default direct GPIO map

- GPIO2..GPIO9: Buttons 1..8, active low
- GPIO10: Hat Up
- GPIO11: Hat Right
- GPIO12: Hat Down
- GPIO13: Hat Left
- GPIO16: MCP3208 MISO
- GPIO17: MCP3208 CS
- GPIO18: MCP3208 SCK
- GPIO19: MCP3208 MOSI

Inputs use the Pico internal pull-ups.

## Calibration console

Connect to the CDC serial port. Commands:

```text
help
status
cal show
cal set <axis> <min> <center> <max>
invert <axis> <0|1>
deadzone <axis> <0..32766>
filter <axis> <0..5>
expo <axis> <0..100>
save
defaults
```

Axis names:
`roll pitch collective throttle pedals brake_left brake_right`

Changes are made in RAM first. Use `save` to write a CRC-protected configuration to the final flash sector.

## Physical validation rule

Before saving final calibration:
1. verify magnet alignment,
2. move each mechanism through full mechanical travel,
3. inspect `status` raw values,
4. leave electrical headroom before mechanical hard stops,
5. enter measured min/center/max,
6. test simulator direction and center,
7. only then save.
