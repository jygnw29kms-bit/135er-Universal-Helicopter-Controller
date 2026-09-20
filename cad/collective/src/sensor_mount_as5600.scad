include <../../common.scad>
px=42;py=42;ph=4;m3=3.4;m4=4.5;
difference(){plate(px,py,ph,3);cylinder(h=20,d=12,center=true);for(x=[-9,9])for(y=[-9,9])translate([x,y,-1])cylinder(h=ph+2,d=m3);for(x=[-15,15])translate([x,0,0])slot3d(12,m4,ph+2);}
