include <parameters.scad>;

module rounded_plate(x,y,h,r=6){
    linear_extrude(height=h)
        offset(r=r)
            offset(delta=-r)
                square([x,y], center=true);
}

module mounting_holes(){
    for (x=[-90,90])
        for (y=[-70,70])
            translate([x,y,-1])
                cylinder(h=base_h+2,d=m4_clearance);
}

difference(){
    rounded_plate(base_x,base_y,base_h,8);

    // Service cavity leaves structural perimeter.
    translate([0,0,4])
        cube([base_x-2*wall-20,base_y-2*wall-20,base_h],center=true);

    mounting_holes();
}

// Simple central gimbal mounting rails.
for (x=[-55,55])
    translate([x,0,base_h])
        cube([12,100,12],center=true);
