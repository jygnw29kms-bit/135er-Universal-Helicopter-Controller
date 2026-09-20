# V1.1 / RC2 Validation Checklist

The repository may be a buildable release candidate, but it is not a physically validated controller until every required item below has passed on real hardware.

## Stage 0 - dimensional coupons
- [ ] 608 bearing pocket selected
- [ ] 8 mm shaft fit selected
- [ ] 10 mm shaft fit selected
- [ ] 22 mm tube fit selected
- [ ] 6 mm magnet pocket fit selected
- [ ] M3/M4/M5 clearances selected
- [ ] chosen compensation values recorded

## Cyclic mechanical
- [ ] inner/outer gimbal print cleanly
- [ ] bearings seat without cracking or excessive play
- [ ] 8 mm steel pivots fit correctly
- [ ] +/-15 degree pitch travel without interference
- [ ] +/-15 degree roll travel without interference
- [ ] mechanical hard stops protect sensors/cables
- [ ] centering springs return consistently if fitted
- [ ] grip halves fit and remain rigid under normal control loads
- [ ] PTT / force-trim / hat controls can be serviced without reprinting the gimbal

## Collective mechanical
- [ ] 10 mm pivot fit confirmed
- [ ] collective remains in position with friction adjusted
- [ ] friction is smooth through full travel
- [ ] twist throttle rotates freely without moving collective
- [ ] grip fasteners remain accessible
- [ ] wiring does not wind up through throttle travel

## Pedals mechanical
- [ ] main 10 mm yaw shaft fit confirmed
- [ ] yaw rocker travels freely
- [ ] left toe-brake pivot fits and returns
- [ ] right toe-brake pivot fits and returns
- [ ] applying either toe brake does not shift yaw position
- [ ] pedal/rocker structure shows no visible flex under normal foot load

## Hall sensor alignment
- [ ] all magnets are diametrically magnetized
- [ ] magnet centers are aligned to sensor axes
- [ ] sensor air gaps are repeatable
- [ ] no axis electrically clips before its mechanical hard stop
- [ ] center noise is recorded for roll/pitch/yaw
- [ ] raw min/center/max values recorded for all seven axes

## Electrical
- [ ] 3.3 V rail verified before connecting sensors
- [ ] sensor supply and MCP3208 reference verified
- [ ] common ground continuity verified
- [ ] all seven outputs remain within ADC input/reference range
- [ ] MCP3208 SPI communication stable
- [ ] USB cable strain relief fitted
- [ ] module connectors are keyed/labeled
- [ ] analog harness is routed away from noisy/high-current wiring where practical

## USB / firmware
- [ ] HID joystick enumerates
- [ ] CDC console enumerates
- [ ] USB serial number is unique/stable across reconnects
- [ ] all seven axes enumerate
- [ ] direct buttons 1-8 operate
- [ ] hat cardinal directions operate
- [ ] hat diagonals operate
- [ ] opposite hat directions cancel safely
- [ ] `cal show` reports live raw values
- [ ] calibration survives power cycle after `save`
- [ ] CRC/default fallback tested once
- [ ] inversion works
- [ ] deadzone works without losing full endpoints
- [ ] filter settings work
- [ ] expo works on bipolar axes
- [ ] `loop_overruns` remains zero or acceptably low during sustained operation
- [ ] no visible startup axis sweep after USB connection

## Simulator
- [ ] MSFS mapping test
- [ ] X-Plane mapping test
- [ ] cyclic directions correct
- [ ] collective direction correct
- [ ] pedal direction correct
- [ ] left/right toe brakes map independently
- [ ] throttle behavior tested on at least one piston helicopter
- [ ] throttle/governor behavior tested on at least one turbine helicopter where applicable
- [ ] buttons and hat map reliably

## Endurance
- [ ] minimum 30 minute powered idle test
- [ ] minimum 30 minute continuous control-movement test
- [ ] USB reconnect test
- [ ] power-cycle calibration persistence test
- [ ] fast full-travel movement does not cause missed/erratic reports
- [ ] no fastener loosening after first flight session

Only after the required checks pass may a release be tagged **VALIDATED**.
