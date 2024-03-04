#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"

#include "color.h"
#include "hittable.h"
#include "material.h"

#include <iostream>


class camera
{
    public:
        double  aspect_ratio        = 4.0 / 3.0;
        int     image_width         = 640;
        int     samples_per_pixel   = 10; //random samples per pixel, we use this for anti aliasing
        int     max_depth           = 10; //number of ray bounces allowed

        double   vfov = 90;               //Field of view is the vertical view angle
        point3   lookfrom             =   point3(0, 0, -1); // Looking from one unit back
        point3   lookat               =   point3(0, 0, 0);  // Looking at 0, 0, 0
        vec3     vup                  =   vec3(0, 1, 0);    // Camera-relative up direction

        double defocus_angle    = 0;
        double focus_dist       = 10;


        void render(const hittable& world, int colormode) 
        {
            initialize();

            std::cout << "P3\n" << image_width << ' ' << image_height << "\n" << colormode-1 << "\n";

            for (int j = 0; j < image_height; ++j)
            {
                std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
                for (int i = 0; i < image_width; ++i)
                {
                    color pixel_color(0,0,0);
                    for (int sample = 0; sample < samples_per_pixel; ++sample)
                    {
                        ray r = get_ray(i, j);
                        pixel_color += ray_color(r, max_depth, world);
                    }

                    write_color(std::cout, pixel_color, samples_per_pixel, colormode);
                }
            }   
            std::clog << "\rDone.                      \n";
        }

    private:
        int     image_height;
        point3  center;
        point3  pixel00_loc;
        vec3    pixel_delta_u;
        vec3    pixel_delta_v;
        vec3    u, v, w;
        vec3    defocus_disk_u;
        vec3    defocus_disk_v;


        void initialize()
        {
            image_height = static_cast<int>(image_width / aspect_ratio);
            image_height = (image_height < 1 ) ? 1 : image_height;
            // top is an if statement, c++ reminder
            
            center = lookfrom;
/*
            // Determine viewport dimensions.
            double focal_length = 1.0;
            double viewport_height = 2.0;
            double viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);
            // Calculate the vectors across the horizontal and down the vertical viewport edges
            vec3 viewport_u = vec3(viewport_width, 0, 0);
            vec3 viewport_v = vec3(0, -viewport_height, 0);
  */

            double focal_length = (lookfrom - lookat).length();
            double theta = degrees_to_radians(vfov);
            double h = tan(theta/2);
            double viewport_height = 2 * h * focal_length;
            double viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);
            
            // Calculate u,v,w unit basis vector for camera
            w = unit_vector(lookfrom - lookat);
            u = unit_vector(cross(vup, w));
            v = cross(w, u);

            // Calculate the vectors across the horizontal and down the vertical viewport edges
            vec3 viewport_u = viewport_width * u;
            vec3 viewport_v = viewport_height * -v;
            
            // Calculate the horizontal and vertical delta vectors from pixel to pixel.
            pixel_delta_u = viewport_u / image_width;
            pixel_delta_v = viewport_v /image_height;

            //Calculate the location of the upper left pixel.
            vec3 viewport_upper_left = center -(focal_length * w) - viewport_u/2 - viewport_v/2;
            pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
        }


        color ray_color(const ray& r, int depth, const hittable& world) const
        {
            hit_record rec;

            if(depth <= 0)
                return color(0, 0, 0);

            if(world.hit(r, interval(0.001,infinity), rec))
            {

                //vec3 direction = rec.normal + random_unit_vector();
                //return 0.5 * ray_color(ray(rec.p, direction), depth-1, world);

                ray scattered;
                color attenuation;
                if (rec.mat->scatter(r, rec, attenuation, scattered))
                    return attenuation * ray_color(scattered, depth-1, world);
                return color(0, 0, 0);
            }

            vec3 unit_direction = unit_vector(r.direction());
            double a = 0.5*(unit_direction.y() + 1.0);
            return (1.0-a)*color(1.0,1.0,1.0) + a*color(0.5, 0.7, 1.0);
        }


        ray get_ray(int i, int j)
        {
            vec3 pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            vec3 pixel_sample = pixel_center + pixel_sample_square();

            vec3 ray_origin = center;
            vec3 ray_direction = pixel_sample - ray_origin;

            return ray(ray_origin, ray_direction);
        }


        vec3 pixel_sample_square() const
        {
            double px = -0.5 + random_double();
            double py = -0.5 + random_double();
            return (px * pixel_delta_u) + (py * pixel_delta_v);
        }

};

#endif
