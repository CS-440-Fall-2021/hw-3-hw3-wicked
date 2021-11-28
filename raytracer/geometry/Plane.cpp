#include "Plane.hpp"
#include <sstream>
#include "../utilities/Ray.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/BBox.hpp"

Plane::Plane(): a(0), n(0,0,1) {}


Plane::Plane(const Point3D &pt, const Vector3D &n) {
    a = pt;
    this->n = n;
    this->n.normalize(); 
}

Plane::Plane(const Plane &object) : a(object.a), n(object.n) {}

Plane& Plane::operator=(const Plane &rhs) {
    a = rhs.a;
    n = rhs.n;
    return *this;
}

std::string Plane::to_string() const 
{
    return a.to_string() + " " + n.to_string();
}

bool Plane::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
    float tmin = (a - ray.o) * n/(ray.d * n);
    if (tmin > kEpsilon)
    {
        t = tmin;
        s.normal = n;
        s.normal.normalize();
        s.hit_point = ray.o + (t * ray.d);
        s.ray = ray; s.t = t;
        return true;
    }
    return false;
}

BBox Plane::getBBox() const 
{
    BBox b;
    return b;
}
