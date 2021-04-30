#ifndef COLOR_H
#define COLOR_H

#include "util.h"
/**
 * @brief Color class hold RGB values and we can mix colors or operate any +-/* with color
 * 
 */
class Color 
{
public:
    short int r,g,b;    // color elements
    
    Color(short int r=0,short int g=0, short int b=0)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    static Color from_hex(std::string hex_str)
    {   //Create Color RGB using color hex string 
        // string should be start from '#' (#ffffff)

        std::string R="";
        R = R + hex_str[1] + hex_str[2];
        
        std::string G="";
        G = G + hex_str[3] + hex_str[4];
        
        std::string B="";
        B = B + hex_str[5] + hex_str[6];

        Color new_col(hexToInt(R),hexToInt(G),hexToInt(B));
        return  new_col;
    }

    Color operator +(Color col)
    {
        col.r += this->r;
        col.b += this->b;
        col.g += this->g;
        
        col.r = (col.r > 255)? 255:col.r;
        col.b = (col.b > 255)? 255:col.b;
        col.g = (col.g > 255)? 255:col.g;

        return  col;
    }

    Color operator +(short int num)
    {   Color col;
        col.r = this->r + num;
        col.b = this->b + num;
        col.g = this->g + num;
        
        col.r = (col.r > 255)? 255:col.r;
        col.b = (col.b > 255)? 255:col.b;
        col.g = (col.g > 255)? 255:col.g;

        return  col;
    }

    Color operator -(Color col)
    {
        col.r -= this->r;
        col.b -= this->b;
        col.g -= this->g;
        
        col.r = (col.r < 0)? 0:col.r;
        col.b = (col.b < 0)? 0:col.b;
        col.g = (col.g < 0)? 0:col.g;

        return  col;
    }

    Color operator -(short int num)
    {
        Color col;
        col.r = this->r - num;
        col.b = this->b - num;
        col.g = this->g - num;
        
        col.r = (col.r < 0)? 0:col.r;
        col.b = (col.b < 0)? 0:col.b;
        col.g = (col.g < 0)? 0:col.g;

        return  col;
    }


    Color operator *(short int num)
    {
        Color col;
        col.r = this->r * num;
        col.b = this->b * num;
        col.g = this->g * num;
        
        col.r = (col.r > 255)? 255:col.r;
        col.b = (col.b > 255)? 255:col.b;
        col.g = (col.g > 255)? 255:col.g;

        return  col;
    }

    Color operator /(short int num)
    {
        Color col;
        col.r = this->r / num;
        col.b = this->b / num;
        col.g = this->g / num;
        
        col.r = (col.r < 0)? 0:col.r;
        col.b = (col.b < 0)? 0:col.b;
        col.g = (col.g < 0)? 0:col.g;

        return  col;
    }

    Color operator [](short int index)
    { // Return Index Color
        switch (index)
        {
            case 0: return this->r;
                    break;
            case 1: return this->b;
                    break;
            case 2: return this->g;
                    break;
        
            default: throw std::out_of_range("Color are RGB use 0,1,2 for get values");
                    break;
        }
    }


};

std::ostream &operator<<(std::ostream &os, Color const &col) { 
    return os <<"Color("<<col.r<<","<<col.g<<","<<col.b<<")" ;
}

#endif