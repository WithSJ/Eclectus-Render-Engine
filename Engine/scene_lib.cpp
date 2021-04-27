#include "sphere_lib.cpp"

class Scene
{
    // Scene is a container that have all objects including camera.
    // it will use in render.

    public:
        Vector Camera;
        Sphere* Objects; 
        short int NumberOfObjects;
        short int Width, Height;
        
        Scene(Vector camera, Sphere objects[], short int number_of_objects, short int width, short int height)
        {
            this->Camera = camera;
            this->Objects = objects;
            this->NumberOfObjects = number_of_objects;
            this->Width = width;
            this->Height = height;
        }
};