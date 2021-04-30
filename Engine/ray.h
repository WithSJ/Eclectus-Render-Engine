#ifndef RAY_H
#define RAY_H

#include "vector.h"

/**
 * @brief Ray is Define by a Point and Direction this ray we use as Light Rays to 
 * hit object get there propertis and light effects 
 * 
 */
class Ray
{
    private:
        /* data */
    public:
        Vector Origin, Direction;

        Ray(Vector origin, Vector direction)
        {
            this->Origin = origin;
            this->Direction = direction.normalize(direction);
        }
};

#endif