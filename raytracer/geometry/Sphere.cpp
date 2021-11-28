#include "Sphere.hpp"
#include "ShadeInfo.hpp"

Sphere::Sphere()
{
    c(0, 0, 0);
}

Sphere::Sphere(const Point3D &center, float radius)
{
    c(center.x, center.y, center.z);
    r = radius;
}

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
    c = c.to_string();
    std::stringstream rad;
    rad << r;

    std::string rad_str = rad.str();
    return c + " " + rad_str;
}

virtual bool Sphere::hit(const Ray &ray, float &t, ShadeInfo &s) const 
{
    float tmin = t;
    Vector3D temp = ray.o - c;
    float t1 = ray.d * ray.d;
    float t2 = 2.0 * temp * ray.d;
    float t3 = temp * temp - r * r;
    float dis = t2 * t2 - 4.0 * t1 * t3;

    if (dis < 0.0)
    {
        return false;
    }
    else 
    {	
		float e = sqrt(dis);
		float denominator = 2.0 * t1;
		tmin = (-t2 - e) / denominator;    // smaller root
	
		if (tmin > kEpsilon) {
			t = tmin;
			sr.normal 	 = (temp + tmin * ray.d) / r;
			sr.hit_point = ray.o + tmin * ray.d;
			return true;
		} 
	
		tmin = (-t2 + e) / denominator;    // larger root
	
		if (tmin > kEpsilon) {
			t = tmin;
			sr.normal   = (temp + tmin * ray.d) / r;
			sr.hit_point = ray.o + tmin * ray.d;
			return true;
		} 
	}
}

virtual BBox Sphere::getBBox() const 
{
    Point3D pmin, pmax;
    pmin(c.x - r, c.y - r, c.z - r);
    pmax(c.x + r, c.y + r, c.z + r);
    return BBox(pmin, pmax);
}