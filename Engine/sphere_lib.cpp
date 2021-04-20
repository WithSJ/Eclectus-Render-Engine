#include "vector_lib.cpp"
#include "color_lib.cpp"

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
};