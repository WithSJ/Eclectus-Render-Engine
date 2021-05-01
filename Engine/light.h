#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"
#include "color.h"

/**
 * @brief Light have Postion and Color Values using this values we can genrated light effects.
 * @version 1.1
 */
class Light
{
private:
    /* data */
public:
    Vector position;
    Color color;
    
    Light(const Vector& position, const Color& color)
    {
        this->position = position;
        this->color = color;
    }
    
};

#endif
