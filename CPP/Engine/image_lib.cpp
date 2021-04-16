#include "color_lib.cpp"

class Image
{
    private:
        /* data */
    public:
        short int HEIGTH=0, WIDTH=0;
        Color** PIXCELS;
        
        Image(short int height, short int width)
        {   this->HEIGTH = height; // Assigen Height and Width
            this->WIDTH = width;
            
            this->PIXCELS = new Color* [WIDTH]; // Create pixcels accorfing Height and Width
            for (short int i = 0; i < WIDTH; i++)
            {
                this->PIXCELS[i] = new Color [HEIGTH];
            }
            
        }
    
    
    


        
};