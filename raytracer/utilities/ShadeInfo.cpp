#include "ShadeInfo.hpp"
#include "Constants.hpp"

ShadeInfo::ShadeInfo(const World& wr): hit(false), material_ptr(nullptr), hit_point(), normal(), 
                                       ray(), depth(0), t(kEpsilon), w(&wr) {}