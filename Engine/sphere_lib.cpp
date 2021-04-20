#include<math.h>

#include "vector_lib.cpp"
#include "color_lib.cpp"
#include "ray_lib.cpp"

class Sphere
{
    public:
        Vector Center;
        float Radius; 
        Color Material;

        Sphere(Vector center, float radius, Color material)
        {
            this->Center = center;
            this->Radius = radius;
            this->Material = material;
        }

        float intersects(Ray ray)
        {
            Vector sphere_to_ray = ray.Origin - this->Center;

            float a = 1.0;

            float b = 2 * ray.Direction.dot_product(sphere_to_ray);

            float c = sphere_to_ray.dot_product(sphere_to_ray) - this->Radius * this->Radius;

            float discriminant = b * b - 4 * a * c;

            if (discriminant >= 0)
            {
                float distance = (-b - sqrt(discriminant)) / 2;
                if(distance>0)
                    return distance;
            }

            return NULL;

        }
};