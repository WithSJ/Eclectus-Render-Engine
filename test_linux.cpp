#include <iostream>
#include <chrono>

#include "Engine/renderengine.h"

using namespace std::chrono;

#include <sys/time.h>
#include <sys/resource.h>
long memory_usage()
{
    rusage Musage;
    getrusage(RUSAGE_SELF,&Musage);
    return Musage.ru_maxrss;
}

int main(int argc, char const *argv[])
{
    /* code */
    // Eclectus Testing 1.0
    auto start = high_resolution_clock::now();

    long base_memory = memory_usage();

    /* code */
    short int WIDTH = 1080;
    short int HEIGHT = 1920;
    
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
    


    long used_memory = memory_usage()-base_memory;
    std::cout<<"\n#Memory Used\n";
    std::cout<<"\n#Memory used(bits) by Program : "<< used_memory;
    std::cout<<"\n#Memory used(bytes) by Program : "<< float(used_memory)/8;
    std::cout<<"\n#Memory used(KB) by Program : "<< (float(used_memory)/8)/1024;
    std::cout<<"\n#Memory used(MB) by Program : "<< ((float(used_memory)/8)/1024)/1024;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    float d = float(duration.count())/1000000.0;
    
    std::cout<<"\n\n#Time Used\n";

    std::cout<<"\n#Time takes in microseconds: "<< duration.count();
    std::cout<<"\n#Time takes in seconds: "<< d;
    std::cout<<"\n#Time takes in minutes: "<< d/60<<std::endl;
    
    return 0;
}
