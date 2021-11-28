#include <iostream>
#include "Geometry.hpp"
#include "Ray.hpp"
#include "BBox.hpp"


Geometry::Geometry()
{
    material_ptr = NULL;
}

Material* Geometry::get_material() const
{
    return material_ptr;
}

void Geometry::set_material(Material *mPtr)
{
    if (material_ptr != NULL)
    {
        delete material_ptr;
    }
    material_ptr = mPtr;
}
