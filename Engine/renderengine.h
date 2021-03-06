#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include<math.h>

#include "scene.h"

/**
 * @brief 
 * 
 * @version 1.1
 */
class RenderEngine
{
    public:
        /**
         * @brief Rendering 3d Scene in 2D Image to view that scene.
         * with using Camera,Lights and Objects. Ray calculate color for Image.
         * 
         * @param scene 
         * @return Image 
         */
        Image render(Scene& scene)
        {
            /**
             * @brief Calculate Aspect Ratio for Camera and Ray.
             * Aspect_Ratio =  width / height
             *            Y0 -Y
             *      -------------- 
             * -X   |            |   +X
             * X0   | screen     |   X1
             *      --------------
             *            Y1  +Y
             * 
             * x0 = -1.0 and x1 = +1.0 we not need to change x ratio 
             * 
             * y0 = -1.0 / Aspect_Ratio 
             * and
             * y1 = +1.0 / Aspect_Ratio
             * we need to change y ratio according to Aspect_Ratio
             * 
             * Calculate Xstep and Ystep later use it for calculate X and Y 2d Vector
             * 
             * Xstep = (x1-x0) / width - 1
             * Ystep = (x1-x0) / height - 1
             * 
             *
             */
            float aspect_ratio = float(scene.Width) / scene.Height;
            float x0 = -1.0, x1 = +1.0;
            float y0 = -1.0 / aspect_ratio, y1 = +1.0 / aspect_ratio;

            float xstep = (x1-x0) / (scene.Width - 1);
            float ystep = (y1-y0) / (scene.Height - 1);

            // Set Image Height and Width in Pixcels 2d matrix
            Image pixcels(scene.Height, scene.Width);

            /**
             * @brief Calculate X and Y For Ray.
             * Ray from Camera to X and Y  2d point
             */
            float x, y;

            for(short int i=0; i < scene.Height; i++)
            {
                y = y0 + i * ystep;
                
                for(short int j=0; j < scene.Width; j++)
                {
                    x = x0 + j * xstep;
                    //  Now we calculated X,Y 

                    Ray ray_cast(scene.Camera, Vector(x,y) - scene.Camera);
                    // Casting a Ray using Camera and X,Y pos

                    pixcels.set_pixcel(i,j,ray_trace(ray_cast,scene));
                    // set color values in Pixcels matrix (Image data)


                }
            }

            return pixcels; // Return Rendered image data
        }
        
        /**
         * @brief Shoot Ray and find object in scene where hit that ray
         * using that hit_pos and hit_normal we calculate Color on that pos.
         * 
         * @param ray 
         * @param scene 
         * @return Color 
         */
        Color ray_trace(Ray& ray, Scene& scene)
        {
            Color color(0,0,10); // Background Color
            /**
             * @brief Itrate all object from scene.Objects to calculate all objects
             * hit_pos and hit normal
             * 
             */

            Sphere t;
            for (short i = 0; i < scene.NumberOfObjects -1; i++)
            {
                // Sort all Objects according to there magnitude
                // we need this
                float a = scene.Objects[i].Center.magnitude();
                float b = scene.Objects[i+1].Center.magnitude();
                if( a > b )
                {
                    t = scene.Objects[i];
                    scene.Objects[i] = scene.Objects[i+1];
                    scene.Objects[i+1] = t;

                }
            }

            Vector hit_pos, hit_normal;
            Sphere object;
            float distance;

            for(short int i = 0;i<scene.NumberOfObjects;i++)
            {
                object = scene.Objects[i]; // first object in objects Array
                distance = object.intersects(ray); // first object ray intersecing distance
                
                // we want min distance of object from one ray
                if(distance >= 0.0)
                {
                    // // Calculate Ray where hit.
                    hit_pos = ray.Origin + ray.Direction * distance;
                    hit_normal = object.normal(hit_pos);

                    return color_at(object,hit_pos,hit_normal,scene);
                }
            }

            Vector dir = ray.Origin.normalize();
            float tt = 0.5 * (dir.y + 1.0);
            color = Color(255,255,255) * float(1.0-tt) + Color(short(255*0.5),short(255*0.7),short(255)) * float(tt);

            
            return color;
        }

        /**
         * @brief Calcuate Color values using Object, hit_pos, normal, from scene
         * color depends on all shading and lighting in scene.
         * 
         * @param object_hit 
         * @param hit_pos 
         * @param normal 
         * @param scene 
         * @return Color 
         */
        Color color_at(Sphere& object_hit, const Vector& hit_pos, Vector& normal, Scene& scene)
        {

            Vector to_cam = scene.Camera - hit_pos;
            Color color;
         
            // Itrate all lights 
            float NL,HN;
            for(short int i = 0; i < scene.NumberOfLigths; i++)
            {
                Ray to_light = Ray(hit_pos, scene.Lights[i].position - hit_pos);

                /**
                 * @brief Diffuse Shading (We use Lambert Shading Model for Diffuse)
                 * 
                 * First Calculate N.L so we multiply it with disffuse value 
                 * but problem is our Color class can hold shot int values 
                 * we need to convert it in first we multiply it with 255 than
                 * convert it with usiing short class now we can get actual values
                 * but we need to invert this value if we want to apply that in color values.
                 * 255-diffusevalue now substract that from actual color of sphere
                 * 
                 */
                
                // Calculate N.L(dot product) this value can't be in negative. is should be in 0 to 1.0
                NL = std::max<float>(normal.dot_product(to_light.Direction),0.0);
                color = color + (object_hit._Material->color_at_hit(hit_pos) * object_hit._Material->Diffuse * NL);

                /**
                 * @brief Specular Shading (We use Blinn-Phong Shading Model)
                 * 
                 */
                
                Vector Half_vec = (to_light.Direction + to_cam).normalize();
                HN = std::max<float>(normal.dot_product(Half_vec) ,0.0);
                float specularHardness = 50;
                color = color + scene.Lights[i].color * (object_hit._Material->Specular * pow(HN, specularHardness));
                
            }
            // return object_hit.Material;
            return color;
        }
};

#endif