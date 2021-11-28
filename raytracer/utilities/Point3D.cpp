#include "Point3D.hpp"
#include <cmath>

Point3D()
{
    x = 0;
    y = 0;
    z = 0;
}

Point3D(float c)
{
    x = c;
    y = c;
    z = c;
}

Point3D(float x, float y, float z)
{
    x = x;
    y = y; 
    z = z;
}

std::string to_string()
{
    std::stringstream s_x, s_y, s_z;
    s_x << x;
    s_y << y;
    s_z << z;

    std::string str_x = s_x.str();
    std::string str_y = s_y.str();
    std::string str_z = s_z.str();

    return str_x + str_y + str_z;
}

Point3D operator-() const
{
    Point3D p;
    p.x = -x;
    p.y = -y;
    p.z = -z;
    return p;
}

Vector3D operator-(const Point3D &p) const
{
    // AB = B - A
    Vector3D vector;
    vector.x = p.x - x;
    vector.y = p.y - y;
    vector.z = p.z - z;
    return vector;
}

Point3D operator+(const Vector3D &v) const
{
    Point3D point;
    point.x = v.x + x;
    point.y = v.y + y;
    point.z = v.z + z;
    return point;
}

Point3D operator-(const Vector3D &v) const
{
    Point3D point;
    point.x = v.x - x;
    point.y = v.y - y;
    point.z = v.z - z;
    return point;   
}

Point3D operator*(const float s) const
{
    Point3D point;
    point.x = x * s;
    point.y = y * s;
    point.z = z * s;
    return point;
}

float d_squared(const Point3D &p) const
{
    return (pow(x,  2)+pow(y, 2) + pow(z, 2), 2);
}

float distance(const Point3D &p) const
{
    float square = d_squared(p);
    return pow(square, 1/2);
}

Point3D operator*(const float a, const Point3D &pt)
{
    pt.x = pt.x * a;
    pt.y = pt.y * a;
    pt.z = pt.z * a;
    return pt;
}

Point3D min(const Point3D& a, const Point3D& b)
{
    return Point3D(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z));
    
}

Point3D max(const Point3D& a, const Point3D& b)
{
    return Point3D(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z));
}