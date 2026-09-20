include <../../common.scad>
x=190;y=90;h=16;m4=4.5;shaft=10.3;
difference(){plate(x,y,h,8);for(xx=[-80,80])for(yy=[-35,35])translate([xx,yy,-1])cylinder(h=h+2,d=m4);}
for(xx=[-38,38]){translate([xx,0,h])cube([14,56,46],center=true);translate([xx,0,h+22])rotate([90,0,0])cylinder(h=70,d=shaft,center=true);}
