include <parameters.scad>;

use <base.scad>
use <gimbal_roll.scad>
use <gimbal_pitch.scad>
use <sensor_mount_as5600.scad>

// Visual assembly placeholder.
// Individual production parts are exported from their own SCAD files.

color("gray") import("../export/base_v0.1.stl");
