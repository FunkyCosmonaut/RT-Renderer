#ifndef RAY_H
#define RAY_H

#include "vec3.h"


typedef struct {
    point3 origin;
    vec3 direction;
} Ray;

point3 origin(Ray ray);
point3 at(double t, Ray ray);
vec3 direction(Ray ray);


#endif