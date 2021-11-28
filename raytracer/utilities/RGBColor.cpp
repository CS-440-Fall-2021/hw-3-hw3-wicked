#include "RGBColor.hpp"
#include <string>
#include <sstream>
#include <cmath>

RGBColor::RGBColor():r(0), g(0), b(0) {}

RGBColor::RGBColor(float c):r(c), g(c), b(c) {}

RGBColor::RGBColor(float _r, float _g, float _b)
{
    r = _r;
    g = _g;
    b = _b;
}

std::string RGBColor :: to_string() const
{
    std::stringstream s_r, s_g, s_b;
    s_r << r;
    s_g << g;
    s_b << b;

    std::string str_r = s_r.str();
    std::string str_g = s_g.str();
    std::string str_b = s_b.str();

    return str_r + str_g + str_b;
    
}

RGBColor RGBColor::operator+(const RGBColor &c) const
{
    RGBColor temp;
    temp.r = c.r + r;
    temp.g = c.g + g;
    temp.b = c.b + b;
    return temp;
}

RGBColor& RGBColor::operator+=(const RGBColor &c){
    r += c.r;
    g += c.g;
    b += c.b;
    return *this;
}

RGBColor RGBColor::operator*(const float a) const
{
    RGBColor temp;
    temp.r = r * a;
    temp.g = g * a;
    temp.b = b * a;
    return temp;
}

RGBColor& RGBColor::operator*=(const float a){
    r *= a;
    g *= a;
    b *= a;
    return *this;
}

RGBColor RGBColor::operator/(const float a) const
{
    RGBColor temp;
    temp.r = r / a;
    temp.g = g / a;
    temp.b = b / a;
    return temp;
}

RGBColor& RGBColor::operator/=(const float a){
    r /= a;
    g /= a;
    b /= a;
    return *this;
}

RGBColor RGBColor::operator*(const RGBColor &c) const{
    return RGBColor(r*c.r, g*c.g, b*c.b);
}

bool RGBColor::operator==(const RGBColor &c) const{
    return (r == c.r && g == c.g && b == c.b);
}

RGBColor RGBColor :: powc(float p) const
{
    RGBColor temp;
    temp.r = pow(temp.r, p);
    temp.g = pow(temp.g, p);
    temp.b = pow(temp.b, p);
    return temp;
}

float RGBColor:: average() const
{
    return (r + g + b)/3;
}

RGBColor operator*(const float a, const RGBColor &c){
    return RGBColor(a*c.r, a*c.g, a*c.b);
}