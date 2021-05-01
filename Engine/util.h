#ifndef UTIL_H
#define UTIL_H

#include <sstream>

/**
 * @brief This function convert sting color values in integer values of RGB
 * "#ff00ff" first char of this string '#' will ignore 
 *  after that get 2 char from string and convert that base16 value to base10 values
 * so Color value will be R = 255, G = 0, B = 255
 * @version  1.1
 * @param hex_str 
 * @return int 
 */
int hexToInt(const std::string hex_str)
{
    int x;
    std::stringstream ss;
    ss << std::hex << hex_str;
    ss >> x;
    return x;
}

#endif