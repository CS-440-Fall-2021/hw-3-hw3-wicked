#include "Point3D.hpp"
#include "Vector3D.hpp"
#include <sstream>
#include <cmath>

Point3D :: Point3D()
{
    x = 0;
    y = 0;
    z = 0;
}

Point3D :: Point3D(float c)
{
    x = c;
    y = c;
    z = c;
}

Point3D :: Point3D(float x, float y, float z): x(x), y(y), z(z) {}

std::string Point3D:: to_string() const
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

Point3D Point3D:: operator-() const
{
    return Point3D(-x, -y, -z);
}

Vector3D Point3D::operator-(const Point3D &p) const
{
    return Vector3D(x - p.x, y - p.y, z - p.z);
}

Point3D Point3D::operator+(const Vector3D &v) const
{
    Point3D point;
    point.x = v.x + x;
    point.y = v.y + y;
    point.z = v.z + z;
    return point;
}

Point3D Point3D :: operator-(const Vector3D &v) const
{
    return Point3D(x - v.x, y - v.y, z - v.z);  
}

Point3D Point3D :: operator*(const float s) const
{
    Point3D point;
    point.x = x * s;
    point.y = y * s;
    point.z = z * s;
    return point;
}

float Point3D::d_squared(const Point3D& p) const
{
    return (std::pow((x - p.x),2) + std::pow((y - p.y),2) + std::pow((z - p.z),2));
}

float Point3D :: distance(const Point3D &p) const
{
    float square = Point3D::d_squared(p);
    return std::pow(square, 1/2);
}

Point3D operator*(const float a, const Point3D &pt)
{
     return Point3D(a*pt.x, a*pt.y, a*pt.z);
}

Point3D max(const Point3D& a, const Point3D& b)
{
    return Point3D(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z));
    
}

Point3D min(const Point3D& a, const Point3D& b)
{
    return Point3D(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z));
}