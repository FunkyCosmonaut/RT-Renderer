#include "color.h"
#include "vec3.h"
#include <stdio.h>


void write_color(FILE* out, color pixel_color)
{
    int tx = (int)(255.999 * pixel_color.x);
    int ty = (int)(255.999 * pixel_color.y);
    int tz = (int)(255.999 * pixel_color.z);

    fprintf(out, "%d %d %d\n", tx, ty, tz);
}