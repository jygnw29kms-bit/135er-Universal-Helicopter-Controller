$fn=64;len=145;od=42;id=22.7;
difference(){intersection(){rotate([0,90,0])cylinder(h=len,d=od,center=true);translate([0,12,0])cube([len+4,od,od+4],center=true);}rotate([0,90,0])cylinder(h=len+4,d=id,center=true);}
