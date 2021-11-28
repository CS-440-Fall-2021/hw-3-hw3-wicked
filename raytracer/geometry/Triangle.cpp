#include "Triangle.hpp"
#include "Geometry.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"
#include "BBox.hpp"

Triangle::Triangle()
{
    v0(0); v1(0); v2(0);
}

Triangle::Triangle(const Point3D &a, const Point3D &b, const Point3D &c)
{
    v0(a); v1(b); v2(c);
}

Triangle::Triangle(const Triangle &object)
{
    v0(object.v0); v1(object.v1); v2(object.v2);
}

Triangle& Triangle::operator=(const Triangle &rhs)
{
    if (this == rhs)
    {
        return (*this);
    }
    v0(rhs.v0); v1(rhs.v1); v2(rhs.v2);
    return *this;
}

std::string Triangle::to_string() const 
{
    return v0.to_string() + v1.to_string() + v2.to_string();
}

virtual bool Triangle::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
    Vector3D vec1 = v1 - v0;
    Vector3D vec2 = v2 - v0;
    Vector3D normal = vec1 ^ vec2;
    normal.normalize();

    if (ray.d * normal == 0)
    {
        return false;
    }
    t = ((v0 - ray.o) * normal)/(ray.d *normal);
    if (t < 0)
    {
        return false;
    }

    Point3D hit = ray.o + ray.d * t;

    float a = ((hit.x - v2.x) * (v0.y - v2.y) - (hit.y - v2.y)*(v0.x - v2.x))/((v1.x - v2.x)*(v0.y - v2.y) - (v1.y - v2.y)*(v0.x - v2.x));
    float b = ((hit.x - v2.x) - (a)*(v1.x - v2.x))/(v0.x - v2.x);
    float c = 1 - b - a;

    if (0 > b || 1 < b || 0 > a || 0 < a || 0 > c || 1 < c)
    {
        return false;
    }

    s.t = t;
    s.ray = ray;
    s.hit = true;
    s.hit_point = hit;
    s.normal = normal;
    s.normal.normalize();
    s.material_ptr = this->get_material();

    return true;
}

virtual BBox Triangle::getBBox() const 
{
    float x = 0.00001;
    BBox temp;
    temp.pmin(std::min(std::min(v0.x, v1.x), v2.x) - x, std::min(std::min(v0.y, v1.y), v2.y) - x, std::min(std::min(v0.z, v1.z), v2.z) - x); 
    temp.pmax(std::max(std::max(v0.x, v1.x), v2.x) - x, std::max(std::max(v0.y, v1.y), v2.y) - x, std::max(std::max(v0.z, v1.z), v2.z) - x);

    return temp;
}