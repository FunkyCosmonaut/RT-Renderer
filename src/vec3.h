
typedef struct {
    double x;
    double y;
    double z;
} vec3;

vec3 vadd(vec3 a, vec3 b){
    vec3 result = {a.x + b.x, a.y + b.y, a.z + b.z};
    return result;
}
