#include "Engine/renderengine_lib.cpp"

int main(int argc, char const *argv[])
{
    /* code */
    // Eclectus Testing 1.0

    short int WIDTH = 320;
    short int HEIGHT = 200;
    
    Vector Camera(0,0,-1);
    Color col(255,0,0);
    Sphere obj1(Vector(0,0,1),0.5,col);
    Sphere Objects[] = {obj1};
    Scene scene(Camera,Objects,1,WIDTH,HEIGHT);

    RenderEngine engine;

    Image img =  engine.render(scene);

    img.write_ppm("Eclectus_test.ppm");
    
    return 0;
}
