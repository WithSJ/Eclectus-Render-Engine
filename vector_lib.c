#include<math.h>

typedef struct 
{
    /* data */
    float x,y,z;
}Vector;

Vector _add_ (Vector vec_1, Vector vec_2)
{ 
    //Add two vector points and return Vector
    Vector add_vec;

    add_vec.x = vec_1.x + vec_2.x;
    add_vec.y = vec_1.y + vec_2.y;
    add_vec.z = vec_1.z + vec_2.z;
    
    return  add_vec;
}

Vector _sub_ (Vector vec_1, Vector vec_2)
{ 
    //Add two vector points and return Vector
    Vector add_vec;

    add_vec.x = vec_1.x - vec_2.x;
    add_vec.y = vec_1.y - vec_2.y;
    add_vec.z = vec_1.z - vec_2.z;
    
    return  add_vec;
}

Vector _mul_ (Vector vec_1, float num)
{ 
    //Add two vector points and return Vector
    Vector add_vec;

    add_vec.x = vec_1.x * num;
    add_vec.y = vec_1.y * num;
    add_vec.z = vec_1.z * num;
    
    return  add_vec;
}

Vector _div_ (Vector vec_1, float num)
{ 
    //Add two vector points and return Vector
    Vector add_vec;

    add_vec.x = vec_1.x / num;
    add_vec.y = vec_1.y / num;
    add_vec.z = vec_1.z / num;
    
    return  add_vec;
}

float dot_product(Vector vec_1, Vector vec_2)
{
    vec_1.x *= vec_2.x;
    vec_1.y *= vec_2.y;
    vec_1.z *= vec_2.z;

    return (vec_1.x + vec_1.y + vec_1.z);
}

float magnitude(Vector vec_1)
{
    return sqrt(dot_product(vec_1,vec_1));
}

Vector normalize(Vector vec_1)
{
    return _div_(vec_1,magnitude(vec_1));
}

