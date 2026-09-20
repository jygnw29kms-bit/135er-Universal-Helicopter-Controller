include <../../common.scad>
x=240;y=180;h=12;m5=5.5;
difference(){plate(x,y,h,8);for(xx=[-105,105])for(yy=[-75,75])translate([xx,yy,-1])cylinder(h=h+2,d=m5);}
for(yy=[-42,42])translate([0,yy,h+18])difference(){cube([42,18,48],center=true);rotate([90,0,0])cylinder(h=30,d=10.3,center=true);}
