#include "Triangle.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/BBox.hpp"

Triangle::Triangle(): v0(0), v1(0), v2(0) {}


Triangle::Triangle(const Point3D &a, const Point3D &b, const Point3D &c)
: v0(a), v1(b), v2(c) {}

Triangle::Triangle(const Triangle &object): v0(object.v0), v1(object.v1), v2(object.v2) {}


Triangle& Triangle::operator=(const Triangle &rhs)
{
    v0 = rhs.v0;
    v1 = rhs.v1;
    v2 = rhs.v2;
    return *this;
}

std::string Triangle::to_string() const 
{
    return v0.to_string() + v1.to_string() + v2.to_string();
}

bool Triangle::hit(const Ray& ray, float& t, ShadeInfo& s) const {
    double x1 = v0.x - v1.x;
    double x2 = v0.x - v2.x; 
    double vr1 = v0.x - ray.o.x;
    double y1 = v0.y - v1.y;
    double y2 = v0.y - v2.y;
    double vr2 = v0.y - ray.o.y;
    double z1 = v0.z - v1.z;
    double z2 = v0.z - v2.z;
    double vr3 = v0.z - ray.o.z;

    double m = y2 * ray.d.z - ray.d.y * z2, n = vr2 * ray.d.z - ray.d.y * vr3, p = y2 * vr3 - vr2 * z2;
    double q = ray.d.y * z1 - y1 * ray.d.z, s0 = y1 * z2 - y2 * z1;

    double inverse_dmtr = 1.0 / (x1 * m + x2 * q + ray.d.x * s0);

    double e1 = vr1 * m - x2 * n - ray.d.x * p;
    double beta = e1 * inverse_dmtr;

    if (beta < 0.0){
        return false;
    } 

    double r = y1 * vr3 - vr2 * z1;
    double e2 = x1 * n + vr1 * q + ray.d.x * r;
    double gamma = e2 * inverse_dmtr;

    if (gamma < 0.0)
     return false;

    if (beta + gamma > 1.0){
        return false;}

    double e3 = x1 * p - x2 * r + vr1 * s0;
    double _t = e3 * inverse_dmtr;

	if (_t < kEpsilon)
     return false;

    t = _t;
    s.hit_point = ray.o + (t * ray.d);
	s.normal = (v1 - v0)^(v2 - v0);
	s.normal.normalize();
	s.ray = ray;
	s.t = t;
	return true;
}

BBox Triangle::getBBox() const 
{   
    return BBox(min(min(v0, v1), v2), max(max(v0,v1), v2));
}
