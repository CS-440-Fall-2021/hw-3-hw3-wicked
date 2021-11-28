#include "../cameras/Camera.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"
#include "Simple.hpp"

Simple::Simple (Camera *c_ptr, ViewPlane *v_ptr): camera_ptr(c_ptr), viewplane_ptr(v_ptr) {}

Simple::Simple (const Simple &camera): camera_ptr(camera.camera_ptr), viewplane_ptr(camera.viewplane_ptr) {}

std::vector<Ray> Simple::get_rays(int px, int py) const {
    std::vector<Ray> rays;
    Ray ray;
    Point3D p;
    Vector3D v = viewplane_ptr->bottom_right - viewplane_ptr->top_left;

    float dx = (float)px / (float) viewplane_ptr->hres;
    float dy = (float)py / (float) viewplane_ptr->vres;

    p = viewplane_ptr->top_left + Vector3D(dx*v.x, dy*v.y, 0);

    ray.o = p; 
    ray.d = camera_ptr->get_direction(p);
    ray.d.normalize();
    rays.push_back(r);
    return rays;


}