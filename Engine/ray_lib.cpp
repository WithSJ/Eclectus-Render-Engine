#include "vector_lib.cpp"

class Ray
{
    //Define by Point and Direction
    //Work as light that capture an object show to the camera
    
    private:
        /* data */
    public:
        Vector Origin, Direction;

        Ray(Vector origin, Vector direction)
        {
            this->Origin = origin;
            this->Direction = direction.normalize();
        }
};
