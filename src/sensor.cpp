#include "sensor.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#pragma message ("Current sensor math only works vertically, with normal in direction and center of the default lens axis [z]");

Sensor::Sensor(Geometry::Plane &p, long double sensorWidth, long double sensorHeight, int horizResolution, int vertResolution) {
    setX(p.getX());
    setY(p.getY());
    setZ(p.getZ());
    setDX(p.getDX());
    setDY(p.getDY());
    setDZ(p.getDZ());
    greatestIntensity = 0;
    width = sensorWidth;
    height = sensorHeight;
    horizontalResolution = horizResolution;
    verticalResolution = vertResolution;
    image.reserve(horizResolution);
    for(int x = 0; x < horizResolution; x++) {
        std::vector<unsigned long> tmpv;
        tmpv.reserve(vertResolution);
        image.push_back(tmpv);
        for(int y = 0; y < vertResolution; y++) {
            image.at(x).push_back(0);
        }
    }
}

long double Sensor::getWidth() {
    return width;
}
long double Sensor::setWidth(long double nw) {
    long double old = getWidth();
    width = nw;
    return old;
}
long double Sensor::getHeight() {
    return height;
}
long double Sensor::setHeight(long double nh) {
    long double old = getHeight();
    height = nh;
    return old;
}

Geometry::Point* Sensor::getValidIntersection(Geometry::Line &l) {
    Geometry::Point* p = getIntersection(l);
    if(p == nullptr) {
        return nullptr;
    }
    if(p->getX()>width/2.0 || p->getX()<-1*width/2.0) {    // Out of bounds on the X axis
        return nullptr;
    } else if(p->getY()>height/2.0 || p->getY()<-1*height/2.0) {    // Out of bounds on the Y axis
        return nullptr;
    }

    return p;
}

bool Sensor::addIntersection(Geometry::Point* p, unsigned long it) {
    if(p->getX()<width/2.0 && p->getX()>-1.0*width/2.0) {   // Is a valid X coordinate
        if (p->getY() < width / 2.0 && p->getY() > -1.0 * width / 2.0) {   // Is a valid Y coordinate
            // Then determine the mapping from coordinate space to pixel space.
            // In this case mapping means map the X and Y directly
            long double x = p->getX() / width * horizontalResolution + horizontalResolution / 2; // Convert to [0,horizontalResolution], center to [-horizontalResolution,horizontalResolution]
            long double y = p->getY() / height * verticalResolution + verticalResolution / 2;    // Same operation but on Y axis
            image.at(x).at(y) += it;
            if (image.at(x).at(y) > greatestIntensity) {
                greatestIntensity = image.at(x).at(y);
            }
        }
    }
    //std::cout<<"!"<<std::endl;
}

bool Sensor::writeImage(std::string filename) { // Writes as .ppm. The awesome thing about .ppm is that it supports unlimited color intensities, so I don't need to handle the mapping between internal and display space.
    std::string output = "P3\n" + std::to_string( horizontalResolution ) + "\n" + std::to_string( verticalResolution ) + "\n" + std::to_string(255) + "\n";
    for(int x = 0; x < horizontalResolution; x++ ) {
        for(int y = 0; y < verticalResolution; y++) {
            if(greatestIntensity==0) {
                output += "0 0 0 ";
            } else {
                // output += std::to_string(image.at(x).at(y) * 255 / log(greatestIntensity)) + " ";
                for(int i = 0; i < 3; i++) {
                    output += std::to_string(image.at(x).at(y) > 0 ? 255 : 0 ) + " ";
                }
            }
        }
        output += "\n";
    }

    std::ofstream imageWriter;
    imageWriter.open(filename);
    imageWriter << output << "\n";
    imageWriter.close();

    std::cout<<std::to_string(greatestIntensity)<<std::endl;
}

void Sensor::clearImage() {
    for(std::vector<unsigned long> &v : image) {
        for(int y = 0; y < verticalResolution; y++) {
            v.at(y) = 0;
        }
    }
}