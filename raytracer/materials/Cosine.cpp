#include "Cosine.hpp"
#include "../utilities/ShadeInfo.hpp"

Cosine::Cosine() : color(0) {}

Cosine::Cosine(float c) : color(c) {}

Cosine :: Cosine (float r, float g, float b): color(r, g, b) {}

Cosine::Cosine(const RGBColor &c): color(c) {} 

Cosine::Cosine(const Cosine &other) : color(other.color) {}

Cosine& Cosine::operator=(const Cosine& other) {
    color.r = other.color.r;
	color.g = other.color.g;
	color.b = other.color.b;
    return *this;
}

RGBColor Cosine::shade(const ShadeInfo& sinfo) const {
    return color * (sinfo.normal * (-sinfo.ray.d));
}