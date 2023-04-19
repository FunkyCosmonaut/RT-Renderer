#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

typedef struct hit_record{
    point3 p;
    vec3 normal;
    double t;
} hit_record

typedef struct hittable hittable;

typedef bool (*hit_function)(const hittable *self, const Ray *r,
                            double t_min, double t_max, hit_record *rec);

hittable *hittable_create(hit_function hit_func);
void hittable_destroy(hittable *h);

bool hittabl_hit(const hittable *h const Ray *r, double t_min,
                double t_max, hit_record *rec);