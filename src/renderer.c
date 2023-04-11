#include <stdio.h>
#include "color.h"
#include "vec3.h"

int frender(){

//image
    const double aspect_ratio = 16.0/9.0;
    const int image_width = 400;
    const int image_height = (int)(image_width / aspect_ratio);
//camera
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    vec3 origin = (point3){0, 0, 0};
    vec3 horizontal = (vec3){viewport_width, 0 ,0};
    vec3 vertical = (vec3){0, viewport_height, 0};
    vec3 lower_left_corner = vsub((vsub(vsub(origin, vmul(horizontal, 0.5)),vmul(vertical,0.5))), (vec3){0,0,focal_length});






    printf("P3\n%d %d\n255\n", image_width, image_height);
        
    for(int j = image_height - 1; j >= 0; --j){
        fprintf(stderr, "\rScanlines remaining: %d", j);
        fflush(stderr);
        for(int i = 0; i < image_width; ++i){
            color pixel_color = {(double)i/(image_width-1), (double)j/(image_height-1), 0.25};
            write_color((stdout), pixel_color);
            }
    }
    fprintf(stderr, "\nDone.\n");
    return 0;
}