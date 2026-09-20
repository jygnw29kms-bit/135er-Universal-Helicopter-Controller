include <../../common.scad>
difference(){plate(82,150,12,10);for(y=[-52,52])translate([0,y,-1])cylinder(h=14,d=6.5);for(x=[-24,0,24])for(y=[-35,0,35])translate([x,y,-1])cylinder(h=14,d=8);}
