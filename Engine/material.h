#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"

/**
 * @brief Material class contain BaseColor and all Shader values.
 * @version 1.1
 */
class Material
{
private:
    /* data */
public:
    Color BaseColor;
    float Diffuse;
    
    Material(){}
    Material(const Color& basecolor, float diffuse=1.0)
    {
        this->BaseColor = basecolor;
        this->Diffuse = diffuse;
    }
    
};

#endif