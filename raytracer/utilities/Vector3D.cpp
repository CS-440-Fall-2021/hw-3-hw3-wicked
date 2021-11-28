#include "Vector3D.hpp"

Vector3D()
{
    x = 0;
    y = 0;
    z = 0;
}  

Vector3D(double c)
{
    x = c;
    y = c;
    z = c;
}
Vector3D(double _x, double _y, double _z)
{
    x = _x;
    y = _y;
    z = _z;
}
Vector3D(const Point3D &p)
{
    x = p.x;
    y = p.y;
    z = p.z;
}

Vector3D &operator=(const Point3D &rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return Vector3D(x, y, z);
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

Vector3D operator+(const Vector3D &v) const
{
    return Vector3D(v.x + x, v.y+y, v.z+z);
}

Vector3D &operator+=(const Vector3D &v)
{
    v.x = v.x + x;
    v.y = v.y + y;
    v.z = v.z + z;
    return v;
}

Vector3D operator-(const Vector3D &v) const
{
    return Vector3D(v.x - x, v.y-y, v.z-z);
}

Vector3D operator-=(const Vector3D &v)
{
    v.x = v.x - x;
    v.y = v.y - y;
    v.z = v.z - z;
    return v;    
}

Vector3D operator*(const double a) const
{
    return Vector3D(x*a, y*a, z*a);
}

Vector3D operator/(const double a) const
{
    return Vector3D(x/a, y/a, z/a);
}

void normalize()
{
    float mag = pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 1/2);
    x = x/mag;
    y = y/mag;
    z = z/mag;
}

double length() const
{
    return pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 1/2);
}

double len_squared() const
{
    return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

double operator*(const Vector3D &b) const
{
    return (b.x * x) + (b.y * y) + (b.z * z);
}

Vector3D operator^(const Vector3D &v) const
{
    Vector3D vector;
    vector.x = (y * v.z) - (z * v.y);
    vector.y = -((x * v.z) - (z * v.x));
    vector.z = (x * v.y) - (y * v.x);
    return vector;
}

Vector3D operator*(const double a, const Vector3D &v)
{
    v.x = v.x * a;
    v.y = v.y * a;
    v.z = v.z * a;
    return v;
}