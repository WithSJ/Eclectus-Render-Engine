#ifndef VECTOR_H
#define VECTOR_H

#include<math.h>

/**
 * @brief Vector is use for in so many place as space, point direction and other things.
 * basicly it used for X,Y,Z cordinates.
 * 
 * @version 2.0
 */
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

    Vector operator +(const Vector& vec)
    {
        return Vector(this->x + vec.x, this->y + vec.y, this->z + vec.z);
    }

    Vector operator -(const Vector& vec)
    {   
        return Vector(this->x - vec.x, this->y - vec.y, this->z - vec.z);
    }

    Vector operator *(const Vector& vec)
    {
        return Vector(this->x * vec.x, this->y * vec.y, this->z * vec.z);

    }
    Vector operator *(float num)
    {
        return Vector(this->x * num, this->y * num, this->z * num);

    }

    Vector operator /(const Vector& vec)
    {   
        return Vector(this->x / vec.x, this->y / vec.y, this->z / vec.z);
    }

    Vector operator /(float num)
    {   
        return Vector(this->x / num, this->y / num, this->z / num);
    }

    float dot_product(const Vector& vec)
    {
        return ((this->x * vec.x) + (this->y * vec.y) + (this->z * vec.z));
    }

    float magnitude(const Vector& vec)
    {
        return sqrt(dot_product(vec));
    }

    Vector normalize( Vector& vec_1)
    {
        return vec_1 / magnitude(vec_1);
    }
    

};

std::ostream &operator<<(std::ostream &os, Vector const &vec) { 
    return os <<"Vector("<<vec.x<<","<<vec.y<<","<<vec.z<<")" ;
}

#endif