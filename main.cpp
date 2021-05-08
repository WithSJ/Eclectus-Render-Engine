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
    
    Vector Camera(0, 0, -1);

    Color col = Color::from_hex("#0000ff");
    Material material1(col);
    Sphere obj1(Vector(-0.75, -0.1, 2.25),0.6,material1);

    Color col3 = Color::from_hex("#803880");
    Material material3(col3);
    Sphere obj3(Vector(0.75, -0.1, 1) ,0.6,material3);

    // Ground
    Color Gcol = Color::from_hex("#00ff00");
    Material material2(Gcol);
    Sphere obj2(Vector(0,10000,0),10000,material2);
    
    
    Sphere Objects[] = {obj1,obj2,obj3};    
    
    Color light_col(255,255,255);
    Light point_light(Vector(1.5, -0.5, -10),light_col);
    
    Color light_col2 = Color::from_hex("#E6E6E6");
    Light point_light2(Vector(-0.5, -10.5, 0),light_col2);

    Light Lights[] = {point_light,point_light2};

    Scene scene(Camera,Objects,3,Lights,2,WIDTH,HEIGHT);

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
