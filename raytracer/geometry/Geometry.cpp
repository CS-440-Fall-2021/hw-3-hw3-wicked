#include "../materials/Material.hpp"
#include "Geometry.hpp"

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
        material_ptr = nullptr;
    }
    material_ptr = mPtr;
}

