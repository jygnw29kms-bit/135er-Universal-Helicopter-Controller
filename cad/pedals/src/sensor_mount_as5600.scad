include <../../common.scad>
difference(){plate(42,42,4,3);cylinder(h=12,d=12,center=true);for(x=[-9,9])for(y=[-9,9])translate([x,y,-1])cylinder(h=8,d=3.4);for(x=[-15,15])translate([x,0,0])slot3d(12,4.5,6);}
