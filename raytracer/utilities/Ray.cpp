#include "Ray.hpp"

Ray()
{
    o(0, 0, 0);
    d(0, 0, 0);
    w = 1;
}

Ray(const Point3D &origin, const Vector3D &dir)
{
    o(origin.x, origin.y, origin.z);
    d(dir.x, dir.y, dir.z);
    w = 1;
}

std::string to_string()
{
    std::stringstream s_w;
    s_w << w;

    std::string str_o = o.to_string();
    std::string str_d = d.to_string();
    std::string str_w = s_w.str();

    return str_o + str_d + str_w;
}