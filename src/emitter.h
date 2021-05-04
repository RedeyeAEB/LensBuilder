#ifndef EMITTER_H
#define EMITTER_H

#include <vector>
#include "geometry.h"
#include <string>
#include "light.h"

#pragma message ("make sure to check definitions of radial and axial, I might be using them wrong in this case")
#pragma message ("assumes image is set upon the z-axis as normal")
class EmitterImage : public Geometry::Plane {
private:
    std::vector<std::vector<uint8_t>> image; // Unsigned 8-bit single-channel image
    long double width;
    long double height;
    long double wavelength;
public:
    // Only define the width; the height will be calculated from these file's aspect ratio
    EmitterImage(std::string filename, Geometry::Plane &surface, long double nwidth, long double nheight, long double nwavelength);
    // In this case, radial means going straight from the axis to an edge, axial spinning around
    std::vector<Light::Ray> getDiffuseOutput(unsigned int radialRayCount, unsigned int axialRayCount);
};


#endif
