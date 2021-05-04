#include "emitter.h"

#include <sstream>
#include <fstream>
#include <math.h>
#define PI 3.141592653589793238462643383279 // 30 decimal places of precision should be enough for anyone

#pragma message ("axial ray generator only works on the normal axis, as with other messages")
#pragma message ("PPM conversion must have been done using the linux convert utility, lines may be scrambled otherwise. This code is not fault tolerant.")
EmitterImage::EmitterImage(std::string filename, Geometry::Plane &surface, long double nw, long double nh, long double nwave) {
    // Load the private data before reading the image to memory
    setX(surface.getX());
    setY(surface.getY());
    setZ(surface.getZ());
    setDX(0);   // These are temporary until fixed to work with off-axis
    setDY(0);
    setDZ(1);
    width = nw;
    height = nh;
    wavelength = nwave;
    // Now read the image to memory
    std::string line;
    std::ifstream file(filename);
    if(file.is_open()) {
        std::getline(file, line);   // Consume p3
        std::getline(file, line);   // Grab width and height
        std::istringstream iss(line);
        std::string item;
        std::getline(iss, item, ' ');
        unsigned int pixelw = std::stoi(item, nullptr, 10);
        std::getline(iss, item, ' ');
        unsigned int pixelh = std::stoi(item, nullptr, 10);
        // Now initialize the image vector
        for(int x = 0; x < pixelw; x++) {
            std::vector<uint8_t> internalV;
            internalV.reserve(pixelh);
            for(int y = 0; y < pixelh; y++) {
                internalV.push_back(0);
            }
            image.push_back(internalV);
        }
        std::getline(file, line);   // Consume the intensity
        // Load the actual data separately, otherwise this setup would get too chaotic otherwise
        // First load it into temporary vector due to unpredictable file endings
        std::vector<uint8_t> tmp;
        unsigned int loc = 0;
        tmp.reserve(pixelw*pixelh);
        while(std::getline(file, line)&&loc<pixelh*pixelw) {
            iss = std::istringstream(line); // Grab the next line
            while(std::getline(iss, item, ' ')&&loc<pixelh*pixelw) {
                tmp.push_back(std::stoi(item, nullptr, 10));
                loc++;
            }
        }
        // Now that all the points have been loaded, load it into memory with the proper order
        for(int x = 0; x < pixelw; x++) {
            for(int y = 0; y < pixelh; y++) {
                image.at(x).at(y) = tmp.at(pixelh*y+x);
            }
        }
    }
}
std::vector<Light::Ray> EmitterImage::getDiffuseOutput(unsigned int radialRayCount, unsigned int axialRayCount) {
    // This is what will be returned
    std::vector<Light::Ray> accum;

    // The actual generation
    accum.reserve(radialRayCount*axialRayCount*image.size()*image.at(0).size());    // High resolutions may be a concern
    // Use long double for automatic type conversion
    for(long double xc = 0; xc < image.size(); xc++) {   // Iterate through x pixels
        for(long double yc = 0; yc < image.at(0).size(); yc++) {  // Iterate through y pixels
            // Map their position to world space
            long double x = xc/image.size()*width-width/2;
            long double y = yc/image.at(0).size()*height-height/2;
            // And then generate the actual rays to return
            for(long double r = 0; r < radialRayCount; r++) {   // Using long doubles for automatic conversion later, replace with prettier method later
                for(long double a = 0; a < axialRayCount; a++) {
                    // dx & dy map around the circle, dz only maps to the vertical
                    Light::Ray nextRay(x, y, getZ(), sin(r/radialRayCount/2*PI)*cos(a/axialRayCount*2*PI), sin(r/radialRayCount/2*PI)*sin(a/axialRayCount*2*PI), cos(r/radialRayCount/2*PI), wavelength, image.at(xc).at(yc));    // Starts at the z coord of the plane, action-limited t
                    accum.push_back(nextRay);
                }
            }
        }
    }
    return accum;
}