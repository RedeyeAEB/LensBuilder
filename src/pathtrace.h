#ifndef PATHTRACE_H
#define PATHTRACE_H

#include "geometry.h"
#include "light.h"
#include "opticassembly.h"

class Pathtracer {
private:
    OpticAssembly oa;
public:
    Pathtracer(OpticAssembly noa);

    Geometry::Point traceSingle(Light::Ray r);
    std::vector<Geometry::Point> traceMulti(std::vector<Light::Ray>);
};

#endif
