// 135er Helicopter Controller - collective friction adjuster V1.1
$fn=64;
difference(){
    union(){
        cylinder(h=8,d=42,center=true);
        for(a=[0:45:315])
            rotate([0,0,a]) translate([21,0,0]) cylinder(h=8,d=8,center=true);
    }
    cylinder(h=12,d=5.4,center=true);
    translate([0,0,2.5]) cylinder(h=4,d=9.2,center=true,$fn=6);
}
