//Testing Of Modulles
#include <iostream>
#include<ctime>
#include "Engine/vector_lib.cpp"
#include "Engine/color_lib.cpp"


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

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    float d = float(duration.count())/1000000.0;
    cout<<"\n#Time takes in microseconds: "<< duration.count() <<endl;
    cout<<"\n#Time takes in seconds: "<< d <<endl;
    
    cout<<"\n#---Hex to int---\n\n";
    cout<<"(ff) hex string to int : "<<hexToInt("ff")<<endl;


    cout<<"\n#---Color class---\n\n";

    Color c1(255,0,0); // Color Object from constructor
    cout<<c1<<endl;

    cout<< "Color from hex(#ff0000)"<<endl;
    Color c2 = Color::from_hex("#ff0000"); // Color Object from color hex
    cout<<c2<<endl;
    
    return 0;
}
