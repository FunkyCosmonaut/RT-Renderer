#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"

#include "color.h"
#include "hittable.h"

class camera
{
    public:
        void render(const hittable& world) 
        {
            //placeholder
        }
    private:
        void intialize()
        {
            //placeholder
        }
        color ray_color(const ray& r, const hittable& world) const
        {
            //placeholder
        }

};

#endif
