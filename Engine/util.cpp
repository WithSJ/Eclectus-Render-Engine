#include <sstream>

typedef struct
{
    // Data
    float min_distance = 0.0;
    Sphere object_hit;
}NearestObject;

int hexToInt(std::string hex_str)
{
    int x;
    std::stringstream ss;
    ss << std::hex << hex_str;
    ss >> x;
    return x;
}