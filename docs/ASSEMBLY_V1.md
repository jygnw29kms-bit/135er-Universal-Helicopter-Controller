# Assembly V1 RC1

## Cyclic
1. Print base, outer gimbal, inner gimbal, sensor carriers, magnet hubs and stick clamp in PETG.
2. Fit 608-2RS bearings to the gimbal supports. Tune pocket compensation if required.
3. Use 8 mm steel shafts for pitch and roll pivots.
4. Mount a diametric magnet concentrically in each magnet hub.
5. Mount each AS5600 board coaxially with the magnet; begin around a 2 mm air gap.
6. Clamp a 20-22 mm aluminium tube into the inner gimbal.
7. Verify +/-15 degree movement without interference.
8. Add optional light centering springs only after free movement is confirmed.

## Collective
1. Print base, lever root, two throttle grip halves and sensor carrier.
2. Use a 10 mm steel pivot shaft.
3. Fit the collective Hall sensor coaxially with the pivot magnet.
4. Use a 20-22 mm aluminium lever tube.
5. Fit the throttle grip halves around the tube and place the throttle Hall sensor concentrically at the grip end.
6. Verify free movement before adding friction.

## Pedals
1. Print base, rocker and pedal plates.
2. Use a 10 mm steel main shaft through the center towers.
3. Bolt pedal links to the rocker ends.
4. Fit yaw Hall sensing coaxially with the center shaft.
5. Toe-brake Hall axes are optional modules using the same sensing method.

## Electronics
| MCP3208 | Function |
|---|---|
| CH0 | Cyclic Roll |
| CH1 | Cyclic Pitch |
| CH2 | Collective |
| CH3 | Twist Throttle |
| CH4 | Pedals/Yaw |
| CH5 | Left Toe Brake |
| CH6 | Right Toe Brake |

Reference MCP3208 to Pico 2 wiring: CLK GPIO18, DOUT GPIO16, DIN GPIO19, CS GPIO17, VDD/VREF 3.3 V, common ground.

Before first power-up verify supply polarity and that every Hall output remains inside the ADC range.
