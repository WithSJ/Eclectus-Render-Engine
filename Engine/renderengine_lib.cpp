#include "scene_lib.cpp"
#include "image_lib.cpp"

class RenderEngine
{
    public:
        Image render(Scene scene)
        {
            float aspect_ratio = scene.Width / scene.Height
            float x0 = -1.0, x1 = +1.0;
            float y0 = -1.0 / aspect_ratio, y1 = +1.0 / aspect_ratio;

            float xstep = (x1-x0) / (scene.Width - 1);
            float ystep = (y1-y0) / (scene.Height - 1);

            Image pixcels(scene.Height, scene.Width);
            
            //Here Code that we cast Ray each pixcel 
            // and check that scene.Objects are interset with ray.

            return pixcels // Return Rendered image data
        }
};