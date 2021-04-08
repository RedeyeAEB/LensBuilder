#include "pathtrace.h"

Pathtracer::Pathtracer(OpticAssembly noa) {
    oa = noa;
}
Geometry::Point Pathtracer::traceSingle(Light::Ray r) {

}
std::vector<Geometry::Point> traceMulti(std::vector<Light::Ray> vr) {
    std::vector<Geometry::Point> accum;
    for(Light::Ray r : vr) {
        accum.push_back(Pathtracer::traceSingle(r));
    }
    return accum;
}