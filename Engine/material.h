#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"

/**
 * @brief Material class contain BaseColor and all Shader values.
 * @version 1.3
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

    virtual Color color_at_hit(Vector hit_pos)
    {
        return this->BaseColor;
    }
    
};


class CheckerMaterial : public Material
{
public:
    Color BaseColor2;
    CheckerMaterial(const Color& basecolor,const Color& basecolor2, float diffuse=0.8,float specular=0.5)
    {
        this->BaseColor = basecolor;
        this->BaseColor2 = basecolor2;
        this->Diffuse = diffuse;
        this->Specular = specular;

    }
    Color color_at_hit(Vector hit_pos)
    {
        if(short(abs(hit_pos.x*2))%2 == short(abs(hit_pos.z*2))%2)
        {
            return this->BaseColor;
        }else{
            return this->BaseColor2;
        }
        
    }

    
};


#endif