# Calibration

V1.1 supports persistent per-axis calibration through the USB CDC console.

Bipolar axes:
- Cyclic Roll
- Cyclic Pitch
- Pedals

Unipolar axes:
- Collective
- Throttle
- Left Brake
- Right Brake

## Procedure

1. Print and evaluate the fit-validation parts first.
2. Mechanically assemble the axis with hard stops in place.
3. Align the AS5600 and diametric magnet concentrically.
4. Open the controller CDC serial port.
5. Run `status`.
6. Move the axis to both physical endpoints and record raw values.
7. For bipolar axes record the relaxed mechanical center.
8. Keep a small electrical margin before the mechanical hard stops.
9. Apply the values with `cal set`.
10. Verify direction, center and full travel.
11. Use `save` only after the values are confirmed.

Example:

```text
cal set roll 840 8120 15450
deadzone roll 120
filter roll 2
expo roll 10
save
```

## Acceptance targets

- stable center without visible oscillation
- no electrical clipping before mechanical stops
- full logical range close to mechanical endpoints
- no unintended inversion
- cyclic/pedal center error below 1%
- `loop_overruns` remains zero or negligible during normal operation

The AS5600 magnet must be centered carefully. With a nominal 6 mm magnet, small lateral misalignment has a meaningful effect on angular accuracy.
