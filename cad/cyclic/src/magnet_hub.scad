$fn=64; shaft=8.15; mag=6.15;
difference(){cylinder(h=10,d=18);translate([0,0,-1])cylinder(h=12,d=shaft);translate([0,0,6])cylinder(h=5,d=mag);}
