// 135er Helicopter Controller - Pico 2 + MCP3208 electronics tray V1.1
$fn=48;
x=150; y=95; h=20; wall=3;
difference(){
    minkowski(){cube([x-6,y-6,h-3],center=true);sphere(r=3);}
    translate([0,0,wall]) cube([x-2*wall,y-2*wall,h],center=true);
    // USB cable exit
    translate([x/2,0,3]) cube([10,18,10],center=true);
}
for(p=[[-45,-22],[-45,22],[10,-22],[10,22]])
    translate([p[0],p[1],-h/2+3]) difference(){
        cylinder(h=6,d=8,center=true);
        cylinder(h=8,d=3.0,center=true);
    }
