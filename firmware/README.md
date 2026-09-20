# Firmware

Target platform: RP2350.

## Firmware goals

- Standard USB HID joystick compatibility
- Cross-platform operation
- Seven analog axes
- 16-bit internal axis processing
- Calibration stored in nonvolatile memory
- Filtering without adding noticeable control latency
- Configurable dead zones and response curves
- Multiple aircraft/simulator profiles
- Modular communications support for Cyclic, Collective and Pedals

## Planned pipeline

```text
Hall sensor
  -> raw acquisition
  -> sanity checks
  -> calibration
  -> filtering
  -> curve/dead-zone processing
  -> USB HID report
```

No mandatory desktop driver should be required for normal use.
