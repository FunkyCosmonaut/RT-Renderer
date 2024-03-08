#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hittable.h"
#include "vec3.h"

class triangle : public hittable
{
    public:
        triangle(const point3& _v0, const point3& _v1, const point3& _v2, shared_ptr<material> _material)
         : v0(_v0), v1(_v1), v2(_v2), mat(_material) {}

    bool hit (const ray& r, interval ray_t, hit_record& rec) const override
    {
        vec3 e1 = v1 - v0;
        vec3 e2 = v2 - v0;
        vec3 h = cross(r.direction(), e2);
        double a = dot(e1, h);

        if (fabs(a) < 1e-8) 
        {
            return false;
        }

        double f = 1.0 / a;
        vec3 s = r.origin() - v0;
        double u = f * dot(s, h);
        if ( u < 0.0 || u > 1.0)
        {
            return false;
        }

        vec3 q = cross(s, e1);
        double v = f * dot(r.direction(), q);
        if (v < 0.0 || u + v > 1.0)
        {
            return false;
        }

        double t = f * dot(e2, q);
        if(!ray_t.surrounds(t)) 
        {
            return false;
        }

        rec.t = t;
        rec.p = r.at(t);
        vec3 outward_normal = unit_vector(cross(e1, e2));
        rec.set_face_normal(r, outward_normal);
        rec.mat = mat;

        return true;
    }


    private:
        point3 v0, v1, v2;
        shared_ptr<material> mat;

};

#endif