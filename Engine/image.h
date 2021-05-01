#ifndef IMAGE_H
#define IMAGE_H

#include <fstream>
#include "color.h"

/**
 * @brief Genrated Image 2d Matrix and it can write image file.
 * @version 1.1
 */
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
            
            this->PIXCELS = new Color* [height]; // Create pixcels according Height and Width
            for (short int i = 0; i < height; i++)
            {
                this->PIXCELS[i] = new Color [width];
            }
            
        }

        void set_pixcel(short int x, short int y, const Color& col)
        {
            this->PIXCELS[x][y] = col;
        }

        /**
         * @brief PPM image File Format store data in char by char data 
         * we not need any compresstion any other proccesing things for this.
         * 
         * @param filename 
         */
        void write_ppm(const std::string filename)
        {
            std::ofstream PPM(filename);
            if(PPM.is_open())
            {   // Headder for define file type and Height and Width
                PPM << "P3 " << this->WIDTH << " " << this->HEIGTH << "\n";
                PPM << "255\n"; // Dfine max color used
                PPM << "#Image Render in Eclectus RayCasting Engine.\n";
                for (short int i = 0; i < this->HEIGTH; i++)
                {
                    for (short int j = 0; j < this->WIDTH; j++)
                    {   // Writing Color Value RGB sapareted by space
                        PPM << this->PIXCELS[i][j].r << " " << this->PIXCELS[i][j].g << " " << this->PIXCELS[i][j].b << " ";
                    }
                    PPM<<"\n";
                }
                

            }else{
                throw std::runtime_error("File not open");
            }

        }
    
    
    


        
};

#endif