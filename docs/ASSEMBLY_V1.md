# Assembly V1.1 / RC2 candidate

## Before large prints

Print the validation plate and fit coupons first. Do not freeze bearing, shaft, tube or magnet dimensions from nominal CAD alone.

## Cyclic

1. Print magnet hub, Hall sensor mount, stick clamp, inner/outer gimbals and base.
2. Fit 608-2RS bearings only after selecting the correct printed bearing pocket from the coupon.
3. Use 8 mm steel shafts for pitch and roll pivots.
4. Install diametric magnets concentrically in the magnet hubs.
5. Align each AS5600 directly on the pivot axis.
6. Start with roughly 1-2 mm sensor/magnet air gap and verify actual module behavior before closing the housing.
7. Clamp the 20-22 mm aluminium tube.
8. Verify +/-15 degree travel and hard-stop clearance.
9. Fit the split grip only after the gimbal passes its mechanical test.
10. Install PTT / force-trim / spare switches and the hat mechanism.
11. Add optional light centering springs only after friction-free movement is confirmed.

## Collective

1. Print Hall mount, friction adjuster, lever root, throttle grip halves and base.
2. Install the 10 mm steel pivot.
3. Align collective Hall sensing coaxially with the pivot.
4. Install the lever tube.
5. Assemble the twist throttle and its Hall sensor/magnet pair.
6. Fit friction washers and the printed adjuster.
7. Increase friction gradually; the lever must stay where placed without binding.
8. Add grip buttons/encoder only after the two analog axes are verified.

## Pedals

1. Print yaw sensor mount, rocker, base and both pedal structures.
2. Install the 10 mm steel center shaft.
3. Fit the yaw Hall sensor and magnet coaxially.
4. Print both toe-brake modules.
5. Fit 6 mm toe-brake pivots and independent return springs.
6. Use one Hall sensor/magnet pair per toe brake.
7. Check that left/right brake motion does not mechanically alter the yaw axis.
8. Verify pedal travel and both brake returns before wiring.

## Electronics enclosure

1. Print controller tray and lid.
2. Mount Pico 2 and MCP3208 on standoffs or a carrier board.
3. Keep USB/digital wiring separated from long analog sensor runs where practical.
4. Use locking connectors for modules that may be removed for service.
5. Provide strain relief for USB and external harnesses.

## MCP3208 channel map

| Channel | Function |
|---|---|
| CH0 | Cyclic Roll |
| CH1 | Cyclic Pitch |
| CH2 | Collective |
| CH3 | Twist Throttle |
| CH4 | Pedals/Yaw |
| CH5 | Left Toe Brake |
| CH6 | Right Toe Brake |
| CH7 | Reserved |

SPI:
- MISO/DOUT GPIO16
- CS GPIO17
- SCK GPIO18
- MOSI/DIN GPIO19

Before first power-up verify polarity, common ground and that Hall outputs cannot exceed the ADC reference range.
