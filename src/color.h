#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>


using color = vec3;
/*
void write_color(std::ostream &out, color pixel_color)
{
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}
*/

void write_color(std::ostream &out, color pixel_color, int samples_per_pixel, int colormode)
{
    double r = pixel_color.x();
    double g = pixel_color.y();
    double b = pixel_color.z();

    // Divide the color by the number of samples
    double scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Write the translated [0, 255] value of each color component.
    static const interval intensity(0.000, 0.999);
    out << static_cast<int>(colormode * intensity.clamp(r)) << ' '
        << static_cast<int>(colormode * intensity.clamp(g)) << ' '
        << static_cast<int>(colormode * intensity.clamp(b)) << '\n';

}
#endif
