#include "ray.h"
#include "vec3.h"
#include "color.h"
#include <stdbool.h>
#include <math.h>

point3 origin(Ray ray){
    return ray.origin;
}

point3 at(double t, Ray ray){
    return vadd(ray.origin,  vmul(ray.direction, t));
}

vec3 direction(Ray ray){
    return ray.direction;
}

color ray_color(const Ray ray)
{
  double t = hit_sphere((point3){0,0,-1}, 0.5, ray);
  if (t > 0.0){
    vec3 N = vunit(vsub(at(t, ray), (vec3){0,0,-1}));
    return vmul((color){N.x + 1, N.y + 1, N.z + 1}, 0.5);
  }
  vec3 unit_direction = vunit(ray.direction);
  t = 0.5*(unit_direction.y + 1.0);
  return vadd(vmul((color){1.0,1.0,1.0},(1.0 - t)), vmul((color){0.5,0.7,1.0}, t));
}

double hit_sphere(const point3 center, double radius, const Ray r)
{
    vec3 oc = vsub(r.origin, center);
    double a = vdot(r.direction, r.direction);
    //double b = 2.0 * vdot(oc, r.direction);
    double half_b = vdot(oc, r.direction);
    double c = vdot(oc,oc) - radius*radius;
    //vdot(a,a) can be replaced by a new function
    double discriminant = (half_b*half_b) - (a*c);
    if (discriminant < 0)
    {
        return -1.0;
    }
    else
    {
        return(-half_b - sqrt(discriminant)) / (a);
    }
}

//note that for discriminants of 0 we can signify an edge.