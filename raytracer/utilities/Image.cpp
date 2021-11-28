#include "Image.hpp"
#include "ViewPlane.hpp"
#include <fstream>
#include <cstdio>

Image(int hres, int vres)
{
    hres = hres;
    vres = vres;
}

Image(const ViewPlane &vp)
{
    vp.hres = hres;
    vp.vres = vres;
}

~Image()
{
    delete colors;
    delete hres;
    delete vres;
}

void set_pixel(int x, int y, const RGBColor& color)
{
    colors[y][x] = color;
}

void write_ppm(std::string path) const
{
    // adapted from book
    float max = 0;
    for (int r = 0; r < vres; ++r)
    {
        for (int c=0; c < hres; ++c)
        {
            max = std::max(colors[r][c].r std::max(colors[r][c].g, std::max(colors[r][c].b, max)));
        }
    }

    std::ofstream ofs(path);
    ofs << "P3" << endl << hres << " " << vres << endl << "255" << endl;

    float scale = 255.0/max;
    for (auto j=0; j<vres; ++j)
    {
        for (auto i=0; i <hres; ++i)
        {
            ofs << static_cast<int>(colors[j][i].r * scale) << " " << static_cast<int>(colors[j][i].g * scale) << " " << static_cast<int>(colors[j][i].b * scale);
        }
        ofs << endl;
    }
    ofs.close();
}