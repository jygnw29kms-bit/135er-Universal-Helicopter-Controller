$fn=36;
module bearing_coupon(){ds=[22.0,22.1,22.2,22.3,22.4];difference(){cube([110,34,10]);for(i=[0:4])translate([13+i*21,17,3])cylinder(h=8,d=ds[i]);}}
module shaft_coupon(){d8=[8.0,8.1,8.2,8.3,8.4];d10=[10.0,10.1,10.2,10.3,10.4];difference(){cube([110,50,8]);for(i=[0:4])translate([13+i*21,14,-1])cylinder(h=10,d=d8[i]);for(i=[0:4])translate([13+i*21,36,-1])cylinder(h=10,d=d10[i]);}}
module magnet_coupon(){ds=[6.0,6.1,6.2,6.3,6.4];difference(){cube([110,32,6]);for(i=[0:4])translate([13+i*21,16,3])cylinder(h=4,d=ds[i]);}}
module tube_coupon(){ds=[22.0,22.2,22.4,22.6,22.8];difference(){cube([130,38,8]);for(i=[0:4])translate([15+i*25,19,-1])cylinder(h=10,d=ds[i]);}}
module fastener_coupon(){d3=[3.2,3.4,3.6];d4=[4.2,4.4,4.6];d5=[5.2,5.4,5.6];difference(){cube([105,42,7]);for(i=[0:2])translate([15+i*15,12,-1])cylinder(h=9,d=d3[i]);for(i=[0:2])translate([15+i*15,30,-1])cylinder(h=9,d=d4[i]);for(i=[0:2])translate([65+i*15,21,-1])cylinder(h=9,d=d5[i]);}}
part=is_undef(part)?"bearing":part;
if(part=="bearing")bearing_coupon();if(part=="shaft")shaft_coupon();if(part=="magnet")magnet_coupon();if(part=="tube")tube_coupon();if(part=="fastener")fastener_coupon();
