#include <cmath>
#include <sstream>
#include <iostream>
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/BBox.hpp"
#include "Sphere.hpp"

Sphere::Sphere(): c(0,0,0), r(0) {}

Sphere::Sphere(const Point3D &center, float radius) : c(center), r(radius) {}

Sphere::Sphere(const Sphere &object)
{
    c = object.c;
    r = object.r;
}

Sphere& Sphere::operator=(const Sphere &rhs)
{
    c = rhs.c;
    r = rhs.r;
    return *this;
}

std::string Sphere::to_string() const
{   
    std:: stringstream st;
    st << "c = (" << c.x << "," << c.y << "," << c.z << ")" << " r = " << r;
    return st.str();
}

bool Sphere::hit(const Ray &ray, float &t, ShadeInfo &s) const 
{
    float tmin;
    Vector3D temp = ray.o - c;
    float t1 = ray.d * ray.d;
    float t2 = 2.0 * temp * ray.d;
    float t3 =( temp * temp ) - ( r * r );
    float dis = (t2 * t2) - (4.0 * t1 * t3);

    if (dis < 0.0)
    {
        return false;
    }
    else 
    {	
		float e = std::sqrt(dis);
		float denominator = 2.0 * t1;
		tmin = (-t2 - e) / denominator;    // smaller root
	
		if (tmin > kEpsilon) {
			t = tmin;
			s.normal = (temp + tmin * ray.d) / r;
            s.normal.normalize();
			s.hit_point = ray.o + (tmin * ray.d);
            s.ray = ray; s.t = t;
			return true;
		} 
	
		tmin = (-t2 + e) / denominator;    // larger root
	
		if (tmin > kEpsilon) {
			t = tmin;
			s.normal = (temp + tmin * ray.d) / r;
            s.normal.normalize();
			s.hit_point = ray.o + (tmin * ray.d);
            s.ray = ray; s.t = t;
			return true;
		} 
        return false;
	}
}

BBox Sphere::getBBox() const 
{
    Point3D pmin(c.x - r, c.y - r, c.z - r);
    Point3D pmax(c.x + r, c.y + r, c.z + r);
    return BBox(pmin, pmax);
}
