#include "BBox.hpp"
#include "Ray.hpp"
#include "Constants.hpp"
#include "../geometry/Geometry.hpp"
#include <string>


BBox::BBox(const Point3D& min, const Point3D& max): pmin(min), pmax(max) {}


std::string BBox::to_string() const
{
    std::string min = pmin.to_string();
    std::string max = pmax.to_string();
    return min + " " + max;
}

bool BBox::hit(const Ray &ray, float &t_enter, float &t_exit) const
{
    // Adapted from the listing in the book.
    float ox = ray.o.x;
    float oy = ray.o.y;
    float oz = ray.o.z;
    float dx = ray.d.x;
    float dy = ray.d.y;
    float dz = ray.d.z;

    float tx_min, ty_min, tz_min;
    float tx_max, ty_max, tz_max;

    float a = 1.0/dx;
    if (a >= 0)
    {
        tx_min = (pmin.x - ox) * a;
        tx_max = (pmax.x - ox) * a;
    }
    else
    {
        tx_min = (pmax.x - ox) * a;
        tx_max = (pmin.x - ox) * a;        
    }

    float b = 1.0/dy;
    if (b >= 0)
    {
        ty_min = (pmin.y - oy) * b;
        ty_max = (pmax.y - oy) * b;
    }
    else
    {
        ty_min = (pmax.y - oy) * b;
        ty_max = (pmin.y - oy) * b;        
    }

    float c = 1.0/dz;
    if (c >= 0)
    {
        tz_min = (pmin.z - oz) * c;
        tz_max = (pmax.z - oz) * c;
    }
    else
    {
        tz_min = (pmax.z - oz) * c;
        tz_max = (pmin.z - oz) * c;        
    }

    t_enter = std::max(std::max(tx_min, ty_min), tz_min);
    t_exit = std::min(std::min(tx_max, ty_max), tz_max);

    return (t_enter < t_exit && t_exit > kEpsilon);
}

void BBox::extend(Geometry* g)
{   
    this->pmin = min(g->getBBox().pmin, pmin);
    this->pmax = max(g->getBBox().pmax, pmax);
}

void BBox::extend(const BBox& b)
{
    this->pmin = min(b.pmin, pmin);
    this->pmax = max(b.pmax, pmax);
}

bool BBox::contains(const Point3D& p)
{
    // Checking if it is in the box.
    int flag = 0;
    if (p.x <= pmax.x && p.x >= pmin.x)
    {
        flag++;
    }
    if (p.y <= pmax.y && p.y >= pmin.y)
    {
        flag++;
    }
    if (p.z <= pmax.z && p.z >= pmin.z)
    {
        flag++;
    }
    if (flag == 3)
    {
        return true;
    }

    return false;
}

bool BBox::overlaps(Geometry* g)
{
    BBox temp = g->getBBox();
    return ((pmax.x > temp.pmin.x) && (pmax.y > temp.pmin.y) && (pmax.z > temp.pmin.z));

}

bool BBox::overlaps(const BBox& b)
{
    return ((pmax.x > b.pmin.x) && (pmax.y > b.pmin.y) && (pmax.z > b.pmin.z));
}
