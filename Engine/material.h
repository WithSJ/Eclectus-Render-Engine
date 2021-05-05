#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"

/**
 * @brief Material class contain BaseColor and all Shader values.
 * @version 1.2
 */
class Material
{
private:
    /* data */
public:
    Color BaseColor;
    float Diffuse;
    float Specular;
    
    Material(){}
    Material(const Color& basecolor, float diffuse=0.8,float specular=0.5)
    {
        this->BaseColor = basecolor;
        this->Diffuse = diffuse;
        this->Specular = specular;
    }
    
};

#endif