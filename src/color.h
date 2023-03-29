#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>
#include "vec3.h"

void write_color(FILE* out , color pixel_color){

    int ir = (int)(255.999 * pixel_color.x);
    int ig = (int)(255.999 * pixel_color.y);
    int ib = (int)(255.999 * pixel_color.z);

    fprintf(out, "%i %i %i\n", ir, ig, ib);

}


#endif