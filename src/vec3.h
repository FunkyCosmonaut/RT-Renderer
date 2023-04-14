
#ifndef VEC3_H
#define VEC3_H
//#include <math.h>
#include <stdio.h>



typedef struct {
    double x;
    double y;
    double z;
} vec3;


//Vector operations for vec3
void vec3_out(vec3 v, FILE* out);
vec3 vadd(vec3 a, vec3 b);
vec3 vsub(vec3 a, vec3 b);
vec3 vmul(vec3 a, const double b);
vec3 vdiv(vec3 a, const double b);
const double vdot(vec3 u, vec3 v);
vec3 vcross(vec3 u, vec3 v);
double vmag(vec3 v);
vec3 vunit(vec3 v);

typedef vec3 point3;
typedef vec3 color;

#endif