#ifndef RAY_H
#define RAY_H

#include "vec3.h"
#include <stdbool.h>


typedef struct {
    point3 origin;
    vec3 direction;
} Ray;

double hit_sphere(const point3 center, double radius, const Ray r);
point3 origin(Ray ray);
point3 at(double t, Ray ray);
vec3 direction(Ray ray);
color ray_color(const Ray ray);


#endif