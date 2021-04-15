#include "util.cpp"

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
};

std::ostream &operator<<(std::ostream &os, Color const &col) { 
    return os <<"Color("<<col.r<<","<<col.g<<","<<col.b<<")" ;
}





