#ifndef SENSOR_H
#define SENSOR_H

#include "geometry.h"
#include <vector>

#pragma message ("Only supports intensities of a single channel")
#pragma message ("Only supports human-readable ppm format for writeImage()")
class Sensor: public Geometry::Plane {  // Defaults to square sensor
private:
    long double width;
    long double height;
    int horizontalResolution;
    int verticalResolution;
    std::vector<std::vector<unsigned long>> image; // X axis in first axis, Y axis in second axis
    unsigned long long int greatestIntensity;
public:
    Sensor(Geometry::Plane &p, long double sensorWidth, long double sensorHeight, int horizResolution, int vertResolution);
    long double getWidth();
    long double setWidth(long double nw);
    long double getHeight();
    long double setHeight(long double nh);

    // Carries getIntersection(Geometry::Line) from Geometry::Plane
    // Add getValidIntersection(Geometry::Line) to account for finite plane size
    Geometry::Point* getValidIntersection(Geometry::Line &l);   // Return nullptr if no solution

    // These methods are for actually rendering a point onto the sensor.
    // Maps a Point onto the sensor and updates the count at a given pixel, if valid
    bool addIntersection(Geometry::Point* p, unsigned long it);   // Returns false if invalid point, true otherwise
    bool writeImage(std::string s);  // Writes existing image to a .ppm

    // Tidiness stuff
    void clearImage();
};


#endif
