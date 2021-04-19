#include <fstream>
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

        void set_pixcel(short int x, short int y, Color col)
        {
            this->PIXCELS[x][y] = col;
        }

        void write_ppm(std::string filename)
        {
            std::ofstream PPM(filename);
            if(PPM.is_open())
            {   
                PPM << "P3 " << this->HEIGTH << " " << this->WIDTH << "\n";
                PPM << "255\n";
                PPM << "#Image Render in Eclectus RayCasting Engine.\n";
                for (short int i = 0; i < this->WIDTH; i++)
                {
                    for (short int j = 0; j < this->HEIGTH; j++)
                    {
                        PPM << this->PIXCELS[i][j].r << " " << this->PIXCELS[i][j].g << " " << this->PIXCELS[i][j].b << " ";
                    }
                    PPM<<"\n";
                }
                

            }else{
                throw std::runtime_error("File not open");
            }

        }
    
    
    


        
};