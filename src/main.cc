#include "utils.h"

#include "camera.h"
#include "color.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"


int colormode = 16;


int main(void) 
{
    hittable_list world;

    double R = cos(pi/4);

    auto material_left    = make_shared<lambertian>(color(0,0,1));
    auto material_right   = make_shared<lambertian>(color(1,0,0));

    world.add(make_shared<sphere>(point3(-R, 0, -1), R, material_left));
    world.add(make_shared<sphere>(point3(R, 0,-1), R, material_right));

    camera cam;

    cam.aspect_ratio = 4.0 / 3.0;
    cam.image_width = 640;
    cam.samples_per_pixel = 50;
    cam.max_depth = 5;

    cam.vfov = 120;
    cam.render(world, colormode);

}


