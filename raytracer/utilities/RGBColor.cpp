#include "RGBColor.hpp"
#include <string>
#include <sstream>
#include <cmath>

RGBColor()
{
    r = 0;
    g = 0;
    b = 0;
}

RGBColor(float c)
{
    r = c;
    g = c;
    b = c;
}

RGBColor(float _r, float _g, float _b)
{
    r = _r;
    g = _g;
    b = _b;
}

std::string to_string()
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

RGBColor operator+(const RGBColor &c) const
{
    RGBColor temp;
    temp.r = c.r + r;
    temp.g = c.g + g;
    temp.b = c.b + b;
    return temp;
}

RGBColor &operator+=(const RGBColor &c)
{
    c.r = r + c.r;
    c.g = g + c.g;
    c.b = b + c.b;
    return c
}

RGBColor operator*(const float a) const
{
    RGBColor temp;
    temp.r = r * a;
    temp.g = g * a;
    temp.b = b * a;
    return temp;
}

RGBColor &operator*=(const float a)
{
    RGBColor temp;
    temp.r = temp.r * a;
    temp.g = temp.g * a;
    temp.b = temp.b * a;
    return temp;
}

RGBColor operator/(const float a) const
{
    RGBColor temp;
    temp.r = r / a;
    temp.g = g / a;
    temp.b = b / a;
    return temp;
}

RGBColor &operator/=(const float a)
{
    RGBColor temp;
    temp.r = temp.r / a;
    temp.g = temp.g / a;
    temp.b = temp.b / a;
    return temp;    
}

RGBColor operator*(const RGBColor &c) const
{
    c.r = r * c.r;
    c.g = g * c.g;
    c.b = b * c.b;
    return c;  
}

bool operator==(const RGBColor &c) const
{
    if (c.r == r) && (c.g == g) && (c.b == b)
    {
        return true;
    }
    return false;
}

RGBColor powc(float p) const
{
    RGBColor temp;
    temp.r = pow(temp.r, p);
    temp.g = pow(temp.g, p);
    temp.b = pow(temp.b, p);
    return temp;
}

float average() const
{
    return (r + g + b)/3;
}

RGBColor operator*(const float a, const RGBColor &c)
{
    c.r = c.r * a;
    c.g = c.g * a;
    c.b = c.b * a;
    return c;
}