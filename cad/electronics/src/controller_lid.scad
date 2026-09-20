// 135er Helicopter Controller - electronics lid V1.1
$fn=48;
x=150; y=95; t=3;
difference(){
    minkowski(){cube([x-6,y-6,t-1],center=true);sphere(r=3);}
    for(p=[[-68,-40],[-68,40],[68,-40],[68,40]])
        translate([p[0],p[1],0]) cylinder(h=t+3,d=3.4,center=true);
    // passive ventilation slots
    for(xx=[-45:-15:45])
        translate([xx,0,0]) cube([8,45,t+3],center=true);
}
