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
