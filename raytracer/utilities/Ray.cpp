#include "Ray.hpp"
#include <sstream>

Ray::Ray(): o(0,0,0), d(0,0,0), w(1) {}

Ray::Ray(const Point3D& origin, const Vector3D& dir):o(origin), d(dir), w(1) {}

std::string Ray::to_string() const
{
    std::stringstream s_w;
    s_w << w;

    std::string str_o = o.to_string();
    std::string str_d = d.to_string();
    std::string str_w = s_w.str();

    return str_o + str_d + str_w;
}
