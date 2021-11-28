#include "Image.hpp"
#include "../world/ViewPlane.hpp"
#include "RGBColor.hpp"
#include <fstream>
#include <iostream>
// #include <cstdio>

Image::Image(int hres, int vres)
{
    this->hres = hres;
    this->vres = vres;
    colors = new RGBColor*[vres];
    for (int i=0; i<(hres); i++)
        colors[i] = new RGBColor[hres];

}

Image :: Image(const ViewPlane &vp)
{
    hres = vp.hres;
    vres = vp.vres;
    colors = new RGBColor*[vres];
    for (int i=0; i<(hres); i++)
        colors[i] = new RGBColor[hres];
}

Image::~Image()
{
   for (int i = 0; i < hres; i++)
        delete[] colors[i];
    delete[] colors;
}

void Image :: set_pixel(int x, int y, const RGBColor& color)
{
    colors[y][x] = color;
}

void Image :: write_ppm(std::string path) const
{
    float _max = 0;
    for (int i = 0; i < vres; ++i)
    {
        for (int j=0; j < hres; ++j)
        {
            _max = std::max(colors[i][j].r,std::max(colors[i][j].g, std::max(colors[i][j].b, _max)));
        }
    }

    std::ofstream file(path);
    file << "P3" << '\n';
    file << hres << " " << vres << '\n';
    file << 255 << '\n';

    double scale = 255/_max;
    for(int i = 0; i < vres; i++) 
    {
        for(int j = 0; j < hres; j++)
        {
            file << static_cast<int>(colors[i][j].r*scale) << " " <<
            static_cast<int>(colors[i][j].g*scale) << " " <<
            static_cast<int>(colors[i][j].b*scale) << " "; 
        }
        file << '\n';
    }
    file.close();
}