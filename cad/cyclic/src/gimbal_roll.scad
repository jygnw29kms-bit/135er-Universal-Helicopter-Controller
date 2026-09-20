include <parameters.scad>;

module bar_x(len){
    cube([len,gimbal_bar,gimbal_h],center=true);
}
module bar_y(len){
    cube([gimbal_bar,len,gimbal_h],center=true);
}

difference(){
    union(){
        translate([0,(gimbal_outer_y-gimbal_bar)/2,0]) bar_x(gimbal_outer_x);
        translate([0,-(gimbal_outer_y-gimbal_bar)/2,0]) bar_x(gimbal_outer_x);
        translate([(gimbal_outer_x-gimbal_bar)/2,0,0]) bar_y(gimbal_outer_y);
        translate([-(gimbal_outer_x-gimbal_bar)/2,0,0]) bar_y(gimbal_outer_y);
    }

    // Roll shaft bores.
    rotate([90,0,0])
        cylinder(h=gimbal_outer_y+20,d=shaft_d,center=true);
}
