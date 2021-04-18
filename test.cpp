//Testing Of Modulles
#include <iostream>
#include<ctime>
#include "Engine/vector_lib.cpp"
#include "Engine/image_lib.cpp"


#include <chrono>
using namespace std::chrono;

using namespace std;

int main(int argc, char const *argv[])
{
    auto start = high_resolution_clock::now();
    cout<<"#---Vector class---\n\n";
    Vector v1(1,-2,-2);
    Vector v2(3,6,9);
    cout<<"Vector v1,v2 : "<< v1 <<v2<<endl;
    cout<<"Dot Product : "<< v1.dot_product(v1) << endl;
    cout<<"Magnitude : "<< v1.magnitude(v1) << endl;
    cout<<"Normalize : "<< v1.normalize(v1) << endl;
    cout<<"Add : "<< v1 + v2<<endl;
    cout<<"Sub : "<< v1 - v2<<endl;
    cout<<"Mul : "<< v1 * 2<<endl;
    cout<<"Div : "<< v2 + 3<<endl;

    cout<<"\n#Dot Product v1,v2 : "<< v1.dot_product(v2) << endl;

    
    cout<<"\n#---Hex to int---\n\n";
    cout<<"(ff) hex string to int : "<<hexToInt("ff")<<endl;


    cout<<"\n#---Color class---\n\n";

    Color c1(30,63,255); // Color Object from constructor
    cout<<c1<<endl;

    cout<< "Color from hex(#AABBff)"<<endl;
    Color c2 = Color::from_hex("#AABBff"); // Color Object from color hex
    cout<<c2<<endl;
    cout<< "\n#Color +-*/ operator"<<endl<<endl;
    cout<<c1 <<" + "<<c2<<" : "<<c1 + c2<<endl<<endl;
    cout<<c2 <<" - "<<c1<<" : "<<c2 + c1<<endl<<endl;
    cout<<c1 <<" * "<<2<<" : "<<c1 * 2<<endl<<endl;
    cout<<c2 <<" / "<<10<<" : "<<c2 / 10<<endl<<endl;

    cout<<"Use [] operator " <<c1<<" : "<<c1[0]<<endl;

    //Read Write PPM Image
    cout<<"\n\n#Use of PPM Image"<<endl;

    Image img(3,2);

    Color red(255,0,0);
    Color green(0,255,0);
    Color blue(0,0,255);
    
    img.set_pixcel(0,0,red);
    cout<<red<<endl;
    img.set_pixcel(0,1,green);
    cout<<green<<endl;
    img.set_pixcel(0,2,blue);
    cout<<blue<<endl;

    img.set_pixcel(1,0,red+green);
    cout<<red+green<<endl;
    img.set_pixcel(1,1,red+green+blue);
    cout<<red+green+blue<<endl;

    img.set_pixcel(1,2,red*0);
    cout<<red*0<<endl;

    
    img.write_ppm("test.ppm");
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    float d = float(duration.count())/1000000.0;
    cout<<"\n#Time takes in microseconds: "<< duration.count() <<endl;
    cout<<"\n#Time takes in seconds: "<< d <<endl;
    
    return 0;
}
