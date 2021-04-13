class Color 
{
public:
    short int r,g,b;    
    Color(short int r=0,short int g=0, short int b=0)
    {
        this->r = r;
        this->g = g;
        this->b = b;

    }
};

std::ostream &operator<<(std::ostream &os, Color const &col) { 
    return os <<"Color("<<col.r<<","<<col.g<<","<<col.b<<")" ;
}





