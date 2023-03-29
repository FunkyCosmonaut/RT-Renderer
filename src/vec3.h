#ifndef VEC3_H
#define VEC3_H


typedef struct {
    double x;
    double y;
    double z;
} vec3;


//Vector operations for vec3
vec3 vadd(vec3 a, vec3 b){
    vec3 result = {a.x + b.x, a.y + b.y, a.z + b.z};
    return result;
}

vec3 vsub(vec3 a, vec3 b){
    vec3 result = {a.x - b.x, a.y - b.y, a.z - b.z};
    return result;
}

vec3 vmul(vec3 a, const double b){
    vec3 result = {a.x * b, a.y * b, a.z * b};
    return result;
}
vec3 vdiv(vec3 a, const double b){
    vec3 result = {a.x * (1/b), a.y * (1/b), a.z * (1/b)};
    return result;
}

const double vdot(vec3 u, vec3 v){
    return u.x * v.x + u.y + v.y * u.z + v.z;
}

vec3 vcross(vec3 u, vec3 v){
    vec3 result = {u.z * v.y - u.y * v.z, u.z * v.x - u.x * v.z, u.x * v.y - v.x * u.y};
    return result;
}
