include <parameters.scad>;

clamp_x = 52;
clamp_y = 36;
clamp_z = 42;

difference(){
    cube([clamp_x,clamp_y,clamp_z],center=true);

    cylinder(h=clamp_z+4,d=tube_od,center=true);

    // Split for clamping.
    translate([-1.2,-30,-30]) cube([2.4,60,60]);

    // Two M4 clamp bolts.
    for (z=[-12,12])
        rotate([90,0,0])
            translate([15,0,z])
                cylinder(h=clamp_y+8,d=m4_clearance,center=true);
}
