#include "ray.h"
#include "vec3.h"
#include "color.h"
#include <stdbool.h>

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
    if (hit_sphere((point3){0,0,-1}, 0.5, ray)){
        return (color){1, 0, 0};
    }
    vec3 unit_direction = vunit(ray.direction);
    double t = 0.5*(unit_direction.y + 1.0);
    return vadd(vmul((color){1.0, 1.0, 1.0},1.0-t), vmul((color){0.5, 0.7, 1.0},t));
    
}

bool hit_sphere(const point3 center, double radius, const Ray r){
    vec3 oc = vsub(r.origin, center);
    double a = vdot(r.direction, r.direction);
    double b = 2.0 * vdot(oc, r.direction);
    double c = vdot(oc,oc) - radius*radius;
    double discriminant = (b*b) - (4.0*a*c);
    return (discriminant > 0);
}

//note that for discriminants of 0 we can signify an edge.