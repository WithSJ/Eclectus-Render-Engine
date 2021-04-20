#include "vector_lib.cpp"

class Ray
{
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
