#include "ShadeInfo.hpp"
#include "World.hpp"

ShadeInfo::ShadeInfo(const World &wr)
{
    w = wr;
}

ShadeInfo::ShadeInfo(const ShadeInfo &sr)
{
    hit = sr.hit;
    material_ptr = sr.material_ptr;
    hit_point = sr.hit_point;
    normal = sr.normal;
    ray = sr.ray;
    depth = sr.depth;
    t = sr.t;
    w = sr.w;
}