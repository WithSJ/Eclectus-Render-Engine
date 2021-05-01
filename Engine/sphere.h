#ifndef SPHERE_H
#define SPHERE_H

#include<math.h>

#include "image.h"
#include "ray.h"
#include "material.h"

/**
 * @brief Sphere is Object that we use in our 3d space 
 * Sphere is define by Center point and Radius 
 * using both we can genrate all surface point of sphere. 
 * 
 * It's easy to calculate and we use it for rendering testing
 * 
 * @version 1.1
 */
class Sphere
{
    
    public:
        Vector Center;
        float Radius=0.0; 
        Material _Material;

        Sphere(){}
        Sphere(const Vector& center, float radius, const Material& material)
        {
            this->Center = center;
            this->Radius = radius;
            this->_Material = material;
        }

        /**
         * @brief checking ray is interset with object than what is distance
         * 
         * @param ray 
         * @return float 
         */
        float intersects(Ray& ray)
        {
            
            
            Vector sphere_to_ray = ray.Origin - this->Center;

            float a = 1.0;

            float b = 2 * ray.Direction.dot_product(sphere_to_ray);

            float c = sphere_to_ray.dot_product(sphere_to_ray) - this->Radius * this->Radius;

            float discriminant = b * b - 4 * a * c;

            if (discriminant >= 0)
            {   
                    // calculate distance from camera to object
                    return (-b - sqrt(discriminant) ) / (2.0 * a);
            }

            return -1.0;

        }
        
        /**
         * @brief Calculate normal values where ray hit 
         * it will help in shading.
         * 
         * @param surface_point 
         * @return Vector 
         */
        Vector normal(Vector& surface_point)
        {
            return (surface_point - this->Center).normalize(surface_point);
        }
};

#endif