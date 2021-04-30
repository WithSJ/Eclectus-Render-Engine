#ifndef SPHERE_H
#define SPHERE_H

#include<math.h>

#include "image.h"
#include "ray.h"

class Sphere
{
    // Sphere is a object that we use in our 3d space to test our RayTracer
    // Sphere is Define by Center and Radius
    public:
        Vector Center;
        float Radius=0.0; 
        Color Material;

        Sphere(){}
        Sphere(Vector center, float radius, Color material)
        {
            this->Center = center;
            this->Radius = radius;
            this->Material = material;
        }

        float intersects(Ray ray)
        {
            // Calculate that ray is touch the Sphere or not 
            
            Vector sphere_to_ray = ray.Origin - this->Center;

            float a = 1.0;

            float b = 2 * ray.Direction.dot_product(sphere_to_ray);

            float c = sphere_to_ray.dot_product(sphere_to_ray) - this->Radius * this->Radius;

            float discriminant = b * b - 4 * a * c;

            if (discriminant >= 0)
            {   
                    return (-b - sqrt(discriminant) ) / (2.0 * a);
            }

            return -1.0;

        }

        Vector normal(Vector surface_point)
        {
            return (surface_point - this->Center).normalize(surface_point);
        }
};

#endif