#include "ray.h"
#include "vec3.h"
#include "color.h"

point3 origin(Ray ray){
    return ray.origin;
}

point3 at(double t, Ray ray){
    return vadd(ray.origin,  vmul(ray.direction, t));
}

vec3 direction(Ray ray){
    return ray.direction;
}

color ray_color(const Ray ray){
    vec3 unit_direction = vunit(ray.direction);
    double t = 0.5*(unit_direction.y + 1.0);
    return vadd(vmul((color){1.0, 1.0, 1.0},1.0-t), vmul((color){0.5, 0.7, 1.0},t));
    
}
