#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"
#include "color.h"

class light
{
private:
    /* data */
public:
    Vector position;
    Color color;
    light(Vector position, Color color)
    {
        this->position = position;
        this->color = color;
    }
    
};

#endif
