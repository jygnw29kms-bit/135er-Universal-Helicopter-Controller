# V1 RC1 Validation Checklist

The repository is a design release candidate, not a physically validated production release.

## Mechanical
- [ ] Print every part at least once
- [ ] Verify all parts fit within intended build plate
- [ ] Verify bearing fits
- [ ] Verify 8 mm cyclic shaft fits
- [ ] Verify 10 mm collective/pedal shaft fits
- [ ] Verify cyclic reaches +/-15 degrees without interference
- [ ] Verify collective travel and friction
- [ ] Verify pedal travel
- [ ] Verify AS5600-to-magnet alignment and stable analog output

## Electrical
- [ ] Verify 3.3 V rail
- [ ] Verify all 7 sensor outputs remain in ADC range
- [ ] Verify common ground
- [ ] Verify MCP3208 SPI communications
- [ ] Verify USB enumeration

## Firmware
- [ ] Confirm seven axes enumerate
- [ ] Confirm button/hat report layout
- [ ] Measure center noise
- [ ] Record physical min/center/max values
- [ ] Apply final calibration constants
- [ ] Confirm 1 kHz report loop is stable on target hardware

## Simulator
- [ ] MSFS mapping test
- [ ] X-Plane mapping test
- [ ] Verify collective direction
- [ ] Verify pedal direction
- [ ] Verify throttle behavior on at least one piston and one turbine helicopter
