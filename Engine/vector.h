#ifndef VECTOR_H
#define VECTOR_H

#include<math.h>

/**
 * @brief Vector is use for in so many place as space, point direction and other things.
 * basicly it used for X,Y,Z cordinates.
 * 
 * @version 2.2
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

    float magnitude()
    {   //This method calculate magnitude (length) from 0,0,0
        return sqrt(dot_product(Vector(this->x,this->y,this->z)));
    }

    float magnitude(Vector& point)
    {   //This method calculate magnitude (length) from point Vector
        Vector delta_xyz = Vector(this->x,this->y,this->z) - point;
        return sqrt(delta_xyz.dot_product(delta_xyz));
    }

    Vector normalize()
    {   // normalize (direction) calculated from 0,0,0 vector
        return Vector(this->x,this->y,this->z) / this->magnitude();
    }

    Vector normalize(Vector& point)
    {   // normalize (direction) calculated from point vector
        return Vector(this->x,this->y,this->z) / this->magnitude(point);
    }
    

};

std::ostream &operator<<(std::ostream &os, Vector const &vec) { 
    return os <<"Vector("<<vec.x<<","<<vec.y<<","<<vec.z<<")" ;
}

#endif