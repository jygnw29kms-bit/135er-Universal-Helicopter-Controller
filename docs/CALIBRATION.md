# Calibration

RC1 uses firmware defaults until real mechanical endpoints have been measured.

Bipolar axes: Cyclic Roll, Cyclic Pitch, Pedals.
Unipolar axes: Collective, Throttle, Left Brake, Right Brake.

For each axis record minimum, center where applicable, and maximum raw values. Update the defaults after the first physical build.

Acceptance targets after calibration:
- stable center without visible oscillation,
- no electrical clipping before mechanical stops,
- full logical range close to mechanical endpoints,
- no unintended inversion,
- cyclic/pedal center error below 1%.
