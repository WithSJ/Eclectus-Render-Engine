#ifndef UTIL_H
#define UTIL_H

#include <sstream>

int hexToInt(std::string hex_str)
{
    int x;
    std::stringstream ss;
    ss << std::hex << hex_str;
    ss >> x;
    return x;
}

#endif