#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"

/**
 * @brief Material class contain BaseColor and all Shader values.
 * 
 */
class Material
{
private:
    /* data */
public:
    Color BaseColor;
    float Diffuse;
    
    Material(){}
    Material(Color basecolor, float diffuse=1.0)
    {
        this->BaseColor = basecolor;
        this->Diffuse = diffuse;
    }
    
};

#endif