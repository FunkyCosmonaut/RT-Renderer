#include <stdio.h>
#include "color.h"

int frender(int image_width, int image_height){


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