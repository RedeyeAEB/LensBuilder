#ifndef PATHTRACE_H
#define PATHTRACE_H

#include "geometry.h"
#include "light.h"
#include "opticassembly.h"
#include "emitter.h"
#include "sensor.h"
#include <utility>  // std::pair
#include <vector>   // std::vector

#pragma message ("system does not account for out-of-bound conditions, and does not currently support non-axial optical systems")
#pragma message ("system currently assumes that a ray will pass through all optical surfaces. This isn't always true")
#pragma message ("system only supports single emitter and receiver, no other valid conditions")
namespace Pathtracer {
    std::vector<Light::Ray>* traceLensSystem(LensAssembly &la, Light::Ray &rin, Sensor &sensor);    // Single Ray, returns path of rays
    std::vector<std::vector<Light::Ray>*> traceLensSystem(EmitterImage &emitter, LensAssembly &la, Sensor &sensor);    // Multi Ray
    //std::vector<std::vector<Light::Ray>*> traceLensSystem(const LensAssembly &oa, const std::vector<Light::Ray> &rin);    // Returns the stepped path of light, for each ray respectively
    //std::vector<Light::Ray> traceLensSystem(const LensAssembly &oa, const Light::Ray &rin);
    //std::pair<Light::Ray, Light::Ray> traceSingleLens(const Optic::Lens &l, const Light::Ray &r);
    //std::pair<Light::Ray, Light::Ray> traceSingleLens(const LensAssembly &oa, int index, const Light::Ray &r);
    //std::vector<Light::Ray> traceMultiLens(const LensAssembly &oa, const std::vector<Light::Ray> &vr);
};

#endif
