$fn=64;
module rounded_box2d(x,y,r=4){ offset(r=r) offset(delta=-r) square([x,y],center=true); }
module plate(x,y,h,r=4){ linear_extrude(h) rounded_box2d(x,y,r); }
module slot3d(len,d,h){ hull(){translate([-len/2,0,0])cylinder(h=h,d=d,center=true);translate([len/2,0,0])cylinder(h=h,d=d,center=true);} }
