// 135er Helicopter Controller - modular cyclic grip rear V1.1
$fn=64;
h=145; w=46; tube=22.4;
difference(){
    intersection(){
        hull(){
            translate([0,0,-h/2+18]) scale([1,0.78,1]) sphere(d=w);
            translate([4,0,h/2-28]) scale([1.05,0.82,1.2]) sphere(d=w);
        }
        translate([0,20,0]) cube([80,40,h+20],center=true);
    }
    translate([0,0,-h/2+28]) cylinder(h=65,d=tube,center=true);
    for(z=[-48,0,48]) translate([20,0,z]) rotate([90,0,0]) cylinder(h=50,d=3.4,center=true);
}
