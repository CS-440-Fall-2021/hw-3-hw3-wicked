#include "../utilities/BBox.hpp"
#include "../geometry/Geometry.hpp"
#include "../geometry/Triangle.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../samplers/Sampler.hpp"
#include "../cameras/Camera.hpp"
#include "World.hpp"
#include <iostream>

using namespace std;

World::World():bg_color(0), camera_ptr(NULL), sampler_ptr(NULL) {}

World:: ~World(){
    geometry.clear();
    std::vector<Geometry*>().swap(geometry);
    delete camera_ptr;
    delete sampler_ptr;
}

void World:: add_geometry(Geometry *geom_ptr){
    geometry.push_back(geom_ptr);
}

void World::set_camera(Camera* c_ptr){
    camera_ptr = c_ptr;
}

ShadeInfo World :: hit_objects(const Ray& ray){
    float t; 
    float t_min = kHugeValue;
    ShadeInfo s(*this);
    Vector3D n;
    Point3D p;

    for (unsigned int i = 0; i < geometry.size(); i++){
        if (geometry[i]->hit(ray, t, s) && (t < t_min)){
            s.hit = true;
            s.material_ptr = geometry[i]->get_material();
            t_min = t; 
            n = s.normal;
            p = s.hit_point;
        }
    }
    if (s.hit){
        s.normal = n;
        s.t = t_min;
        s.hit_point = p;
    }
    return s;

}
