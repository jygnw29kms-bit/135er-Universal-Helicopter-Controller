// 135er Helicopter Controller - modular cyclic grip front V1.1
$fn=64;
h=145; w=46; d=34; tube=22.4; wall=3.2;
difference(){
    hull(){
        translate([0,0,-h/2+18]) scale([1,0.78,1]) sphere(d=w);
        translate([4,0,h/2-28]) scale([1.05,0.82,1.2]) sphere(d=w);
    }
    translate([0,7,0]) cube([80,40,h+20],center=true);
    translate([0,0,-h/2+28]) cylinder(h=65,d=tube,center=true);
    // PTT / force-trim / spare switch openings
    translate([-14,-15,28]) rotate([90,0,0]) cylinder(h=12,d=12,center=true);
    translate([10,-15,52]) rotate([90,0,0]) cylinder(h=12,d=10,center=true);
    translate([0,-15,75]) rotate([90,0,0]) cylinder(h=12,d=18,center=true);
    for(z=[-48,0,48]) translate([20,0,z]) rotate([90,0,0]) cylinder(h=50,d=3.4,center=true);
}
