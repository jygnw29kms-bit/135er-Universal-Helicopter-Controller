// 135er Helicopter Controller - right toe brake V1.1
$fn=64;
plate_w=82; plate_h=150; plate_t=10;
pivot_d=6.3; pivot_y=-52;
magnet_d=6.4; magnet_h=3.2;
spring_d=4.4;

mirror([1,0,0])
difference(){
    hull(){
        translate([0,20,0]) cube([plate_w,105,plate_t],center=true);
        translate([0,-50,0]) cylinder(h=plate_t,d=30,center=true);
    }
    translate([0,pivot_y,0]) rotate([0,90,0]) cylinder(h=plate_w+4,d=pivot_d,center=true);
    translate([22,-45,plate_t/2-magnet_h/2]) cylinder(h=magnet_h+0.2,d=magnet_d,center=true);
    translate([-25,-40,0]) cylinder(h=plate_t+2,d=spring_d,center=true);
}
