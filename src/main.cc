#include "utils.h"

#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"


int colormode = 256;


int main(void) 
{
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio = 4.0 / 3.0;
    cam.image_width = 640;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    cam.render(world, colormode);

}


