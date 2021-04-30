#ifndef SCENE_H
#define SCENE_H

#include "sphere.h"
#include "light.h"

/**
 * @brief Scene is a container so we can put all objects, camera, lights
 * it's work as enviroment or world that hold all things.
 * 
 */
class Scene
{
    public:
        Vector Camera;
        Sphere* Objects; 
        short int NumberOfObjects;
        Light* Lights;
        short int NumberOfLigths;
        short int Width, Height;
        
        Scene(Vector camera, Sphere objects[], short int number_of_objects, Light lights[],short int number_of_ligths,short int width, short int height)
        {
            this->Camera = camera;
            this->Objects = objects;
            this->NumberOfObjects = number_of_objects;
            this->Lights = lights;
            this->NumberOfLigths = number_of_ligths;
            this->Width = width;
            this->Height = height;
        }
};

#endif