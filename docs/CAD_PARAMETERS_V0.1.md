# CAD Parameters V0.1

These values are the mechanical baseline for the first Cyclic V1 prototype.

## Global FDM constraints

- Build volume target: 256 x 256 x 256 mm minimum
- Primary material: PETG
- Nominal nozzle: 0.4 mm
- Nominal layer height: 0.20 mm
- Standard wall: 3.2 mm
- Reinforced wall: 5.0-6.0 mm
- Moving-part clearance: 0.30 mm nominal
- Loose service clearance: 0.40 mm nominal
- Bearing pocket allowance: start at +0.10 mm diameter and tune by printer
- Avoid support where possible
- Maximum intended unsupported overhang: 45 deg

## Cyclic base

- Base envelope target: 220 x 180 x 75 mm
- Mounting hole pattern: TBD after first gimbal frame
- Service cover removable from top
- Sensor carriers removable independently from structural gimbal

## Cyclic stick

- Pivot-to-grip reference length: 480 mm
- Tube OD target: 20-22 mm
- Preferred tube: aluminium
- Clamp style: split clamp with M4 fasteners

## Gimbal

- Pitch travel: +/-15 deg
- Roll travel: +/-15 deg
- Main pivot shaft: 8 mm steel
- Bearings: 608-2RS, 8 x 22 x 7 mm
- Gimbal arms should print flat whenever practical
- Bearing housings should be split or clamp-style rather than blind press fits

## Hall sensor geometry

Initial target sensor family:
- AS5600-class absolute magnetic angle sensor for prototype
- Diametric magnet mounted concentric with shaft
- Adjustable sensor gap target: 1-3 mm
- Sensor mount to include slotted adjustment in at least one axis

## Centering

- V1 supports no-spring/free mode
- Optional light centering springs
- Spring anchors must be adjustable
- No mandatory hard center detent

## Fasteners

Preferred standardization:
- M3 for electronics and sensor carriers
- M4 for printed structural joints
- M8 only where used as an actual pivot/shaft substitute
