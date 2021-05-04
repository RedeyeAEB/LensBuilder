#include <iostream>

#include "optic.h"
#include "geometry.h"

Light::Ray Optic::Optic::getPath(Light::Ray &r) {
    std::printf("Warning! This is a dummy method to be superseded by children.");
    return r;
}
Geometry::Point Optic::Optic::getPosition() {
    return axis;    // Geometry::Line multiinherents Point, Vector
}
Geometry::Point Optic::Optic::setPosition(Geometry::Point &p) {
    // A bit more complicated because of the multiinheritance
    Geometry::Point old(axis.getX(),axis.getY(),axis.getZ());
    axis.setX(p.getX());
    axis.setY(p.getY());
    axis.setZ(p.getZ());
    return old;
}
Geometry::Line Optic::Optic::getAxis() {
    return axis;
}
Geometry::Line Optic::Optic::setAxis(Geometry::Line &na) {
    Geometry::Line old = axis;
    axis.setDX(na.getDX());
    axis.setDY(na.getDY());
    axis.setDZ(na.getDZ());
    return old;
}

Optic::Lens::Lens( Geometry::Line &na, long double nr, long double nt, long double nfrontr, long double nbackr, long double n1 ) {
    setAxis(na);
    radius = nr;
    index = n1;
    // Because the front and back are represented as spheres to aid calculations, their positions are calculated here
    // Calculate center of front and assign new sphere
    long double fx = na.getX()+nfrontr*na.getDX()/na.getR();
    long double fy = na.getY()+nfrontr*na.getDY()/na.getR();
    long double fz = na.getZ()+nfrontr*na.getDZ()/na.getR();
    s1 = new Geometry::Sphere(fx, fy, fz, nfrontr); // Front side
    long double bx = na.getX()+na.getDX()/na.getR()*(nt-nbackr);
    long double by = na.getY()+na.getDY()/na.getR()*(nt-nbackr);
    long double bz = na.getZ()+na.getDZ()/na.getR()*(nt-nbackr);
    s2 = new Geometry::Sphere(bx, by, bz, nbackr);  // Back side
    thickness = nt;
}
long double Optic::Lens::getRadius() {
    return radius;
}
long double Optic::Lens::getThickness() {
    return thickness;
}
long double Optic::Lens::getIndex() {
    return index;
}
Geometry::Sphere Optic::Lens::getFront() {
    return *s1;
}
Geometry::Sphere Optic::Lens::getBack() {
    return *s2;
}
long double Optic::Lens::getRadiusFront() {
    return s1->getR();
}
long double Optic::Lens::getRadiusBack() {
    return s2->getR();
}
#pragma message ("getClosesValidIntersection methods only work with a axis vector of <0, 1, 1> centered on z axis")
Geometry::Point* Optic::Lens::getClosestValidIntersectionFront(Light::Ray &r) {  // Return nullptr if no intersection exists
    std::pair<Geometry::Point, Geometry::Point>* intersections = s1->getIntersections(r);
    if(intersections == nullptr) {  // Obvious case, no intersections whatsoever
        return nullptr;
    }
    if(s1->getR() >= 0) {    // Positive curvature, only front side is valid
        if(intersections->first.getZ()<=intersections->second.getZ()) { // If first point is the front one
            Geometry::Point* p = new Geometry::Point(intersections->first.getX(), intersections->first.getY(), intersections->first.getZ());
            if(sqrt(p->getX()*p->getX()+p->getY()*p->getY())>getRadius()) { // Ensures the radius isn't out of bounds
                return nullptr;
            }
            return p;
        } else {
            Geometry::Point* p = new Geometry::Point(intersections->second.getX(), intersections->second.getY(), intersections->second.getZ());
            if(sqrt(p->getX()*p->getX()+p->getY()*p->getY())>getRadius()) { // Ensures the radius isn't out of bounds
                return nullptr;
            }
            return p;
        }
    } else {    // Negative curvature, only back side of sphere is valid
        if(intersections->first.getZ()>=intersections->second.getZ()) { // If first point is the back one
            Geometry::Point* p = new Geometry::Point(intersections->first.getX(), intersections->first.getY(), intersections->first.getZ());
            if(sqrt(p->getX()*p->getX()+p->getY()*p->getY())>getRadius()) { // Ensures the radius isn't out of bounds
                return nullptr;
            }
            return p;
        } else {
            Geometry::Point* p = new Geometry::Point(intersections->second.getX(), intersections->second.getY(), intersections->second.getZ());
            if(sqrt(p->getX()*p->getX()+p->getY()*p->getY())>getRadius()) { // Ensures the radius isn't out of bounds
                return nullptr;
            }
            return p;
        }
    }
}
Geometry::Point* Optic::Lens::getClosestValidIntersectionBack(Light::Ray &r) {
    std::pair<Geometry::Point, Geometry::Point>* intersections = s2->getIntersections(r);
    if(intersections == nullptr) {
        return nullptr;
    }
    if(s2->getR() >= 0) {    // Positive curvature, only front side is valid
        if(intersections->first.getZ()<=intersections->second.getZ()) { // If first point is the front one
            Geometry::Point* p = new Geometry::Point(intersections->first.getX(), intersections->first.getY(), intersections->first.getZ());
            if(sqrt(p->getX()*p->getX()+p->getY()*p->getY())>getRadius()) { // Ensures the radius isn't out of bounds
                return nullptr;
            }
            return p;
        } else {
            Geometry::Point* p = new Geometry::Point(intersections->second.getX(), intersections->second.getY(), intersections->second.getZ());
            if(sqrt(p->getX()*p->getX()+p->getY()*p->getY())>getRadius()) { // Ensures the radius isn't out of bounds
                return nullptr;
            }
            return p;
        }
    } else {    // Negative curvature, only back side of sphere is valid
        if(intersections->first.getZ()>=intersections->second.getZ()) { // If first point is the back one
            Geometry::Point* p = new Geometry::Point(intersections->first.getX(), intersections->first.getY(), intersections->first.getZ());
            if(sqrt(p->getX()*p->getX()+p->getY()*p->getY())>getRadius()) { // Ensures the radius isn't out of bounds
                return nullptr;
            }
            return p;
        } else {
            Geometry::Point* p = new Geometry::Point(intersections->second.getX(), intersections->second.getY(), intersections->second.getZ());
            if(sqrt(p->getX()*p->getX()+p->getY()*p->getY())>getRadius()) { // Ensures the radius isn't out of bounds
                return nullptr;
            }
            return p;
        }
    }
}
std::vector<Light::Ray> Optic::Lens::raytracePath(Light::Ray &r) {
    std::vector<Light::Ray> path;   // Storage variable

    // First, determine the path of light after being refracted by the front surface.
      // Get surface normal
    Geometry::Point* intersection = getClosestValidIntersectionFront(r);
    if(intersection == nullptr) {   // Return empty vector to signify end of the path
        return path;
    }
    Geometry::Vector n = *(s1->getNormal(*(intersection)));
      // Get angle to surface normal -> this is theta1
    long double theta1 = 180 - r.getAngleBetween(n);    // Needs 108 adjustment from opposite normal direction
      // Use snell's to get theta2
    long double theta2 = asin(1/getIndex()*sin(theta1));
    Geometry::Line theAxis = getAxis();
    Geometry::Vector rotationalAxis = n.getCrossProduct(theAxis);
      // Duplicate the ray, rotate it, add to path
    Light::Ray r1(intersection->getX(), intersection->getY(), intersection->getZ(), r.getDX(), r.getDY(), r.getDZ(), r.getWavelength(), r.getIntensity());
    r1.rotateVectorRadians(rotationalAxis, theta1-theta2);
    path.push_back(r1);
    // Second, determine the intersection between that refracted light and the back surface.
    intersection = getClosestValidIntersectionBack(r);
    if(intersection == nullptr) {
        return path;
    }
    n = *(s2->getNormal(*(intersection)));
    theta1 = r.getAngleBetween(n);  // Does not need 180 normal adjustment
    theta2 = asin(getIndex()*sin(theta1));
    rotationalAxis = n.getCrossProduct(theAxis);
    Light::Ray r2(intersection->getX(), intersection->getY(), intersection->getZ(), r.getDX(), r.getDY(), r.getDZ(), r.getWavelength(), r.getIntensity());
    path.push_back(r2);
    // Return the results if a successful output has occurred.
    return path;
}