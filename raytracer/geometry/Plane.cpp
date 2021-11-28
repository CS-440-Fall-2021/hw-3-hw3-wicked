#include "Plane.hpp"
#include "Geometry.hpp"
#include "Vector3D.hpp"
#include "Point3D.hpp"

Plane::Plane()
{
    a(0.0);
}

Plane::Plane(const Point3D &pt, const Vector3D &n)
{
    a(pt);
    n(n);
    n.normalize();
}

Plane::Plane(const Plane &object)
{
    a(object.a);
    n(object.n);
}

Plane& Plane::operator=(const Plane &rhs)
{
    a(rhs.a);
    n(rhs.n);
}

virtual std::string Plane::to_string() const 
{
    return a.to_string() + " " + n.to_string();
}

virtual bool Plane::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
    float tmin = (a - ray.o) * n/(ray.d * n);
    if (tmin > kEpsilon)
    {
        t = tmin;
        s.normal = n;
        s.hit_point = ray.o + t * ray.d;
        return true;
    }
    return false;
}

virtual BBox Plane::getBBox() const 
{
    return BBox();
}