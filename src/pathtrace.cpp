#include "pathtrace.h"

#pragma message ("Warning: Using a break here")
std::vector<Light::Ray>* Pathtracer::traceLensSystem(LensAssembly &la, Light::Ray &rin, Sensor &sensor) { // Single Ray
    /* STEP 1A: Determine the intersection point between all surfaces of each lens, remove extraneous solutions immediately.
     * STEP 1B: Filter out all invalid surfaces (e.g. the current optical intersection, we already dealt with that). Don't filter out a lens surface at the same location
     * STEP 2:  Check if ray goes out-of-bounds (hits side of ray, goes into oblivion)
     * STEP 3:  Solve for closest intersection ray deflection
     */

    /* Alternative steps, better for a messy implementation when low on time such as this one:
     * Literally just trace through the entire lens, surface by surface.
     * A light ray must go from one surface to another, can't go backwards or hit the same surface twice.
     * No intersection gets treated as a dead end.
     */
    std::vector<Light::Ray> path;
    Light::Ray nrin = rin;
    for(Optic::Lens l : la) {
        std::vector<Light::Ray> tmppath = l.raytracePath(nrin);  // Last value in vector returned is the output ray of this lens
            for(Light::Ray r : tmppath) {
            path.push_back(r);
        }
        if(tmppath.size()==0) {
            return &path;
        }
        nrin = path.at(path.size() - 1);
    }
    // If it makes it all the way through add it to the sensor
    Geometry::Point* tp = sensor.getValidIntersection(path.at(path.size()-1));
    if(tp != nullptr) {
        sensor.addIntersection(tp, rin.getIntensity());
    }
    return &path;
}
std::vector<std::vector<Light::Ray>*> Pathtracer::traceLensSystem(EmitterImage &emitter, LensAssembly &la, Sensor &sensor) {
    // Generate the starting set of light rays coming from the surface
    std::vector<Light::Ray> rin = emitter.getDiffuseOutput(4, 5);

    std::vector<std::vector<Light::Ray>*> accum;
    accum.reserve(rin.size());

    std::cout<<std::to_string(rin.size())<<std::endl;
    int count = 0;
    for(Light::Ray r : rin) {
        count++;
        if(count%1000==0)
            std::cout<<std::to_string(count)<<std::endl;
        accum.push_back(traceLensSystem(la, r, sensor));
    }

    return accum;
}







/*
std::pair<Light::Ray, Light::Ray> Pathtracer::traceSingleLens(Optic::Lens &I, const Light::Ray &r) {

}
std::pair<Light::Ray, Light::Ray> Pathtracer::traceSingleLens(LensAssembly &oa, int index, const Light::Ray &r) {
    return Pathtracer::traceSingleLens(oa.at(index), r);
}
std::vector<Light::Ray> traceMultiLens(LensAssembly &oa, const std::vector<Light::Ray> &vr) {
    std::vector<Light::Ray> accum(vr.size());  // Reserve size of length vr
    for(auto &r : vr) {
        Pathtracer::traceSingleLens(r, r)

        accum.push_back();
    }
    return accum;
}*/