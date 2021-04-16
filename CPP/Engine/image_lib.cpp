#include "color_lib.cpp"

class Image
{
    private:
        /* data */
    public:
        int HEIGTH=0, WIDTH=0;
        Color** PIXCELS;
        
        Image(int height, int width)
        {   this->HEIGTH = height; // Assigen Height and Width
            this->WIDTH = width;
            
            this->PIXCELS = new Color* [WIDTH]; // Create pixcels accorfing Height and Width
            for (int i = 0; i < WIDTH; i++)
            {
                this->PIXCELS[i] = new Color [HEIGTH];
            }
            
        }
    
    
    


        
};