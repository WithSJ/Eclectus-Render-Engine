#include <iostream>
#include <chrono>

#include "Engine/renderengine.h"

using namespace std::chrono;

int main(int argc, char const *argv[])
{
    /* code */
    // Eclectus Testing 1.0
    auto start = high_resolution_clock::now();

    short int WIDTH = 320;
    short int HEIGHT = 200;
    
    Vector Camera(0,0,-1);
    Color col = Color::from_hex("#ff0000");
    Material material1(col);
    
    Sphere obj1(Vector(0,0,0),0.3,material1);
    Sphere Objects[] = {obj1};
    
    Color light_col(255,255,255);
    Light point_light(Vector(1.5,-0.5,-3.0),light_col);
    Light Lights[] = {point_light};

    Scene scene(Camera,Objects,1,Lights,1,WIDTH,HEIGHT);

    RenderEngine engine;

    Image img =  engine.render(scene);

    img.write_ppm("Eclectus_test.ppm");

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    float d = float(duration.count())/1000000.0;
    std::cout<<"\n#Time takes in microseconds: "<< duration.count();
    std::cout<<"\n#Time takes in seconds: "<< d<<std::endl;
    
    return 0;
}
