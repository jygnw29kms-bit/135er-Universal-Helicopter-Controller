include <parameters.scad>;

inner_x = 82;
inner_y = 66;
bar = 16;

module bx(len){ cube([len,bar,gimbal_h],center=true); }
module by(len){ cube([bar,len,gimbal_h],center=true); }

difference(){
    union(){
        translate([0,(inner_y-bar)/2,0]) bx(inner_x);
        translate([0,-(inner_y-bar)/2,0]) bx(inner_x);
        translate([(inner_x-bar)/2,0,0]) by(inner_y);
        translate([-(inner_x-bar)/2,0,0]) by(inner_y);

        // Central split-clamp block.
        cube([42,42,32],center=true);
    }

    // Pitch shaft.
    rotate([0,90,0])
        cylinder(h=inner_x+30,d=shaft_d,center=true);

    // Cyclic tube receiver.
    translate([0,0,-20])
        cylinder(h=60,d=tube_od,center=false);

    // Clamp split.
    translate([-1.2,-30,-30])
        cube([2.4,60,70]);

    // Clamp bolt.
    rotate([90,0,0])
        translate([14,0,0])
            cylinder(h=60,d=m4_clearance,center=true);
}
