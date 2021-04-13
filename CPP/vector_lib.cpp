#include<math.h>

class Vector
{
private:
    /* data */
    

public:        
    float x,y,z; //X,Y,Z Elemets
    
    Vector(float x=0.0,float y=0.0, float z=0.0)
    {   // Init Vector Object
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector operator +(Vector vec)
    {
        vec.x = this->x + vec.x;
        vec.y = this->y + vec.y;
        vec.z = this->z + vec.z;
        
        return vec;

    }

    Vector operator -(Vector vec)
    {
        vec.x = this->x - vec.x;
        vec.y = this->y - vec.y;
        vec.z = this->z - vec.z;
        
        return vec;

    }

    Vector operator *(float num)
    {
        Vector vec;
        vec.x = this->x * num;
        vec.y = this->y * num;
        vec.z = this->z * num;
        
        return vec;

    }

    Vector operator /(float num)
    {   Vector vec;
        vec.x = this->x / num;
        vec.y = this->y / num;
        vec.z = this->z / num;
        
        return vec;
    }

    float dot_product(Vector vec)
    {
        vec.x = this->x * vec.x;
        vec.y = this->y * vec.y;
        vec.z = this->z * vec.z;

        return (vec.x + vec.y + vec.z);
    }

    float magnitude(Vector vec)
    {
        return sqrt(dot_product(vec));
    }

    Vector normalize(Vector vec_1)
    {
        return vec_1 / magnitude(vec_1);
    }
    
    

};

std::ostream &operator<<(std::ostream &os, Vector const &vec) { 
    return os <<"("<<vec.x<<","<<vec.y<<","<<vec.z<<")" ;
}



