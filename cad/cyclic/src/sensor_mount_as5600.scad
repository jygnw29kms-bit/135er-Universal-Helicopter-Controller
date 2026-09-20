include <parameters.scad>;

plate_x = 38;
plate_y = 38;
plate_h = 4;

difference(){
    union(){
        cube([plate_x,plate_y,plate_h],center=true);

        // Two adjustment ears.
        for (x=[-17,17])
            translate([x,0,4])
                cube([8,30,8],center=true);
    }

    // Central clearance around magnetic axis.
    cylinder(h=20,d=12,center=true);

    // PCB mounting holes.
    for (x=[-9,9])
        for (y=[-9,9])
            translate([x,y,-10])
                cylinder(h=20,d=m3_clearance,center=true);

    // Slotted structural mounts for adjustment.
    for (x=[-17,17])
        hull(){
            translate([x,-7,4]) rotate([90,0,0]) cylinder(h=20,d=m4_clearance,center=true);
            translate([x, 7,4]) rotate([90,0,0]) cylinder(h=20,d=m4_clearance,center=true);
        }
}
