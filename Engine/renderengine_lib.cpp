#include "scene_lib.cpp"
using namespace std;

class RenderEngine
{
    public:
        Image render(Scene scene)
        {
            float aspect_ratio = scene.Width / scene.Height;
            float x0 = -1.0, x1 = +1.0;
            float y0 = -1.0 / aspect_ratio, y1 = +1.0 / aspect_ratio;

            float xstep = (x1-x0) / (scene.Width - 1);
            float ystep = (y1-y0) / (scene.Height - 1);

            Image pixcels(scene.Height, scene.Width);
            
            //Here Code that we cast Ray each pixcel 
            // and check that scene.Objects are interset with ray.

            for(short int i; i <= scene.Width; i++)
            {
                float x = x0 + i * xstep;
                
                for(short int j; j <= scene.Height; j++)
                {
                    float y = y0 + j * ystep;
                    //  Now we calculated X,Y of pixcel 

                    Ray ray_cast(scene.Camera, Vector(x,y) - scene.Camera);
                    // Casting a Ray using Camera and X,Y pos

                    pixcels.set_pixcel(i,j,ray_trace(ray_cast,scene));
                    // set color values in Pixcels matrix (Image data)


                }
            }

            return pixcels; // Return Rendered image data
        }

        NearestObject find_nearest(Ray ray, Scene scene)
        {
            NearestObject nearestObj_Data;
            // itrate all Objects in scene.objects and find distance where 
            // Ray intersects to object if that distance less than min distance than
            // return that min_distance and object that hit
            // [Code Here]
            nearestObj_Data.min_distance = scene.Objects[0].intersects(ray);
            
            for(Sphere object : scene.Objects)
            {
                if(nearestObj_Data.min_distance < object.intersects(ray))
                {
                    nearestObj_Data.min_distance = object.intersects(ray);
                    nearestObj_Data.object_hit = object;

                }
            }

            return nearestObj_Data;

        }
        Color ray_trace(Ray ray, Scene scene)
        {
            Color color(0,0,0);
            // Find NearestObject hit by the Ray.
            // calculate hit_pos
            // return color of object_hit
            //[Code Here] 

            NearestObject nearestObj_Data;
            
            // Get Nearest object data
            nearestObj_Data = find_nearest(ray,scene); 

            // if Radius is zero thats means there no onject
            if(nearestObj_Data.object_hit.Radius == 0.0)
                return color;
            
            // Calculate Ray where hit.
            Vector hit_pos = ray.Origin + ray.Direction * nearestObj_Data.min_distance;

            // get color data 
            color = color_at(nearestObj_Data.object_hit, hit_pos, scene);
            
            return color;
        }

        Color color_at(Sphere object_hit, Vector hit_pos, Scene scene)
        {
            // Return Hit object color
            // Currently it return only color of object hit.
            // later we use hit_pos and scene
            return object_hit.Material;
        }
};