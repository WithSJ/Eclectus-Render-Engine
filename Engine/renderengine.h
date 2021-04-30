#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include "scene.h"

class RenderEngine
{
    public:
        Image render(Scene scene)
        {
            float aspect_ratio = float(scene.Width) / scene.Height;
            float x0 = -1.0, x1 = +1.0;
            float y0 = -1.0 / aspect_ratio, y1 = +1.0 / aspect_ratio;

            float xstep = (x1-x0) / (scene.Width - 1);
            float ystep = (y1-y0) / (scene.Height - 1);

            Image pixcels(scene.Height, scene.Width);
            
            //Here Code that we cast Ray each pixcel 
            // and check that scene.Objects are interset with ray.

            for(short int i=0; i < scene.Height; i++)
            {
                float y = y0 + i * ystep;
                
                for(short int j=0; j < scene.Width; j++)
                {
                    float x = x0 + j * xstep;
                    //  Now we calculated X,Y of pixcel 

                    Ray ray_cast(scene.Camera, Vector(x,y) - scene.Camera);
                    // Casting a Ray using Camera and X,Y pos

                    pixcels.set_pixcel(i,j,ray_trace(ray_cast,scene));
                    // set color values in Pixcels matrix (Image data)


                }
            }

            return pixcels; // Return Rendered image data
        }
        
        Color ray_trace(Ray ray, Scene scene)
        {
            Color color(0,0,10); // Background Color
            // Find NearestObject hit by the Ray.
            // calculate hit_pos
            // return color of object_hit
            //[Code Here] 

            for(short int i = 0;i<scene.NumberOfObjects;i++)
            {
                Sphere object = scene.Objects[i];
                float distance = object.intersects(ray);
                
                if(distance >= 0.0)
                {
                    // // Calculate Ray where hit.
                    Vector hit_pos = ray.Origin + ray.Direction * distance;
                    Vector hit_normal = object.normal(hit_pos);

                    return color_at(object,hit_pos,hit_normal,scene);
                }
            }
            
            return color;
        }

        Color color_at(Sphere object_hit, Vector hit_pos, Vector normal, Scene scene)
        {
            // Return Hit object color
            // Currently it return only color of object hit.
            // later we use hit_pos,normal and scene 

            Vector to_cam = scene.Camera - hit_pos;
            Color color;
            for(short int i = 0; i < scene.NumberOfLigths; i++)
            {
                Ray to_light = Ray(hit_pos, scene.Lights[i].position - hit_pos);

                // Diffuse Shading (We use Lambert Shading Model for Diffuse)
                
                float NL = std::max<float>(normal.dot_product(to_light.Direction),0.0);

                float diffuse = 1.0;
                
                // std::cout<<object_hit.Material - (255-short(diffuse * NL * 255 ))<<"\n";
                color = object_hit.Material - (255-short(diffuse * NL * 255));
                
            }
            // return object_hit.Material;
            return color;
        }
};

#endif