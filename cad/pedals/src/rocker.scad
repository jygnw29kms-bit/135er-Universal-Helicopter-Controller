$fn=64;shaft=10.3;m6=6.5;
difference(){union(){cube([210,24,22],center=true);cylinder(h=24,d=48,center=true);}rotate([90,0,0])cylinder(h=50,d=shaft,center=true);for(x=[-88,88])cylinder(h=40,d=m6,center=true);}
