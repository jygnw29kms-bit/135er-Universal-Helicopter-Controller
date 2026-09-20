$fn=64;shaft=10.3;tube=22.4;m5=5.5;
difference(){union(){cylinder(h=28,d=50,center=true);translate([32,0,0])cube([64,34,28],center=true);}rotate([90,0,0])cylinder(h=80,d=shaft,center=true);translate([62,0,-20])cylinder(h=40,d=tube);translate([60,-30,-1.3])cube([30,60,2.6]);rotate([90,0,0])translate([54,8,0])cylinder(h=60,d=m5,center=true);}
