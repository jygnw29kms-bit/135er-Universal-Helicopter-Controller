# PRINT FIRST - V1 RC1

Do **not** start with the large cyclic/pedal bases.

Start with `VALIDATION_PLATE_01.stl`. It contains five disconnected fit coupons on one 245 x 137 mm plate.

Use the same printer, nozzle, PETG brand/profile and dimensional settings you intend to use for the final controller.

## Slicer baseline

- 0.4 mm nozzle
- 0.20 mm layer height
- 3 walls for the validation plate
- 4 walls for production controller parts
- 5 top / 5 bottom layers on production parts
- 20% infill for validation plate
- 30-40% infill for production parts
- Supports: OFF
- Scale: 100.00%
- XY compensation / hole compensation: leave at zero/default for the first test
- Print orientation: as supplied, flat on the largest face
- PETG temperatures: use the filament manufacturer's tested/default PETG profile rather than forcing a universal temperature

## Coupon map

### Tube coupon
Left-to-right hole diameters:
22.0 / 22.2 / 22.4 / 22.6 / 22.8 mm

Choose the smallest hole that lets the actual cyclic/collective aluminium tube enter without forcing it.

### Shaft coupon
Upper row, left-to-right:
8.0 / 8.1 / 8.2 / 8.3 / 8.4 mm

Lower row:
10.0 / 10.1 / 10.2 / 10.3 / 10.4 mm

For rotating shafts choose a clean sliding fit with almost no radial play.

### 608 bearing coupon
Left-to-right bearing pocket:
22.0 / 22.1 / 22.2 / 22.3 / 22.4 mm

Choose a pocket where a 608-2RS can be seated by firm thumb pressure and removed without destroying the coupon. Do not choose a brutally tight press fit for PETG.

### Magnet coupon
Left-to-right pocket:
6.0 / 6.1 / 6.2 / 6.3 / 6.4 mm

Choose a snug pocket for the actual diametric magnet. The production hub can additionally retain the magnet with a tiny amount of adhesive.

### Fastener coupon
M3 row:
3.2 / 3.4 / 3.6 mm

M4 row:
4.2 / 4.4 / 4.6 mm

M5 group:
5.2 / 5.4 / 5.6 mm

Choose clearance holes where the screw passes freely without significant slop.

## What to report after this print

Send these five values:
- 608 pocket = __ mm
- 8 mm shaft hole = __ mm
- 10 mm shaft hole = __ mm
- 22 mm tube hole = __ mm
- 6 mm magnet pocket = __ mm
- optional: preferred M3/M4/M5 clearances

Those measurements are the gate for V1 RC1 dimensional freeze. After they are applied, print the Cyclic first, then Collective, then Pedals.
