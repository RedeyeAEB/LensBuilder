#include <iostream>
#include <cmath>
#include "geometry.h"
using namespace Geometry;

Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}
Point::Point( long double nx, long double ny, long double nz ) {
	x = nx;
	y = ny;
	z = nz;
}
long double Point::getX() {
	return x;
}
long double Point::getY() {
	return y;
}
long double Point::getZ() {
	return z;
}
long double Point::setX( long double nx ) {
	long double old = x;
	x = nx;
	return old;
}
long double Point::setY( long double ny ) {
	long double old = y;
	y = ny;
	return old;
}
long double Point::setZ( long double nz ) {
	long double old = z;
	z = nz;
	return old;
}
long double Point::getDistance( Point &p ) {
	return std::pow( std::pow( x - p.getX(), 2 ) + std::pow( y - p.getY(), 2 ) + std::pow( z - p.getZ(), 2 ), .5 );
}
Vector::Vector() {
	dx = 0;
	dy = 0;
	dz = 0;
}
Vector::Vector( long double ndx, long double ndy, long double ndz ) {
	dx = ndx;
	dy = ndy;
	dz = ndz;
}
long double Vector::getDX() {
	return dx;
}
long double Vector::getDY() {
	return dy;
}
long double Vector::getDZ() {
	return dz;
}
long double Vector::setDX( long double ndx ) {
	long double old = dx;
	dx = ndx;
	return old;
}
long double Vector::setDY( long double ndy ) {
	long double old = dy;
	dy = ndy;
	return old;
}
long double Vector::setDZ( long double ndz ) {
	long double old = dz;
	dz = ndz;
	return old;
}
long double Vector::getR() {
	return std::pow( dx * dx + dy * dy + dz * dz, .5 );
}
long double Vector::getMagnitude() {    // Replace with function reference
    return getR();
}
long double Vector::getTheta() {
	if( dx == 0 ) {
		return 0;
	}
	return std::atan( dy / dx );
}
long double Vector::getPhi() {
	if( getR() == 0 ) {
		return 0;
	}
	return std::atan( dz / getR() );
}
long double Vector::setR( long double nr ) {
	long double old = getR();
	if( old == 0 ) {
		return 0;
	}
	dx *= nr / getR();
	dy *= nr / getR();
	dz *= nr / getR();
	return old;
}
long double Vector::setTheta( long double nPhi ) {
	long double r = getR();
	if( r == 0 ) {
		return 0;
	}
	long double oldPhi = getPhi();
	dx = r * std::sin( getTheta() ) * std::cos( nPhi );
	dy = r * std::sin( getTheta() ) * std::sin( nPhi );
	return oldPhi;
}
long double Vector::setPhi( long double nTheta ) {
	long double r = getR();
	if( r == 0 ) {
		return 0;
	}
	long double oldTheta = getTheta();
	dz = r * std::cos( nTheta );
	dx = r * std::sin( nTheta ) * std::cos( getPhi() );
	dy = r * std::sin( nTheta ) * std::sin( getPhi() );
	return oldTheta;
}
Vector Vector::getUnitVector() {
    return Vector(dx/getMagnitude(), dy/getMagnitude(), dz/getMagnitude());
}
long double Vector::getDotProduct( Vector &o ) {
    return o.getDX() * dx + o.getDY() * dy + o.getDZ() * dz;
}
Vector Vector::getCrossProduct( Vector &o ) {
    long double ndx = dy * o.getDZ() - dz * o.getDY();
    long double ndy = dz * o.getDX() - dx * o.getDZ();
    long double ndz = dx * o.getDY() - dy * o.getDX();

    return Vector(ndx, ndy, ndz);
}
long double Vector::getAngleBetween(Vector &o) {
    return acos(getDotProduct(o)/getMagnitude()/o.getMagnitude());
}
Vector Vector::rotateVectorRadians(Vector &rotateAxis, long double radians) {   // Returns this vector, rotated around the other
    Vector unitAxis = rotateAxis.getUnitVector();
    long double cosRad = cos(radians);
    long double sinRad = sin(radians);
    Vector part1 = Vector(dx, dy, dz); // This method would work better if i implemented operators.
        part1.setR(part1.getR()*cosRad);
    Vector part2 = unitAxis.getCrossProduct(*this);
        part2.setR(part2.getR()*sinRad);
    Vector tmp = unitAxis.getCrossProduct(*this);
    Vector part3 = unitAxis.getCrossProduct(tmp);
        part3.setR(part3.getR()*1-cosRad);

    return Vector(part1.getDX()+part2.getDX()+part3.getDX(), part1.getDY()+part2.getDY()+part3.getDY(), part1.getDZ()+part2.getDZ()+part3.getDZ());
}
glm::vec3 Vector::glmvec3()  {
    return glm::vec3(dx,dy,dz);
}
Line::Line() {}
Line::Line( long double nx, long double ny, long double nz, long double ndx, long double ndy, long double ndz ) {
	setX( nx );
	setY( ny );
	setZ( nz );
	setDX( ndx );
	setDY( ndy );
	setDZ( ndz );
}
Line::Line( Point &np, long double ndx, long double ndy, long double ndz ) {
	setX( np.getX() );
	setY( np.getY() );
	setZ( np.getZ() );
	setDX( ndx );
	setDY( ndy );
	setDZ( ndz );
}
Line::Line( Point &np, Vector &nd ) {
	setX( np.getX() );
	setY( np.getY() );
	setZ( np.getZ() );
	setDX( nd.getDX() );
	setDY( nd.getDY() );
	setDZ( nd.getDZ() );
}
Line::Line( Point &a, Point &b ) {
	setX( a.getX() );
	setY( a.getY() );
	setZ( a.getZ() );
	setDX( b.getX() - a.getX() );
	setDY( b.getY() - b.getX() );
	setDZ( b.getZ() - a.getZ() );
}
Sphere::Sphere( long double nx, long double ny, long double nz, long double nr ) {
	setX( nx );
	setY( ny );
	setZ( nz );
	r = nr;
}
Sphere::Sphere( Point &p, long double nr ) {
	setX( p.getX() );
	setY( p.getY() );
	setZ( p.getZ() );
	r = nr;
}
long double Sphere::getR() {
    return r;
}
long double Sphere::setR( long double nr ) {
    long double old = r;
    r = nr;
    return old;
}
bool Sphere::containsPoint( Point &p ) {
	return ( std::pow( p.getX() - getX(), 2 ) + std::pow( p.getY() - getY(), 2 ) + std::pow( p.getZ() - getZ(), 2 ) ) < std::pow( r, 2 );
}
// Treats line as a vector with a given starting point. Intersections of the line behind the starting point will be ignored. Returns the closest intersection found, or nullptr if none is found.
Point* Sphere::getIntersection( Line &l ) {	// http://www.ambrsoft.com/TrigoCalc/Sphere/SpherLineIntersection_.htm
	long double alpha = l.getDX();
	long double beta = l.getDY();
	long double gamma = l.getDZ();
	long double a = alpha * alpha + beta * beta + gamma * gamma;
	long double b = -2 * ( alpha * ( getX() - l.getX() ) + beta * ( getY() - l.getY() ) + gamma * ( getZ() - l.getZ() ) );
	long double c = std::pow( ( getX() - l.getX() ), 2 ) + std::pow( ( getY() - l.getY() ), 2 ) + std::pow( ( getZ() - l.getZ() ), 2 ) - r * r;

	if( ( b * b - 4 * a * c ) < 0 ) {
		return nullptr;
	}

	long double t1 = ( -1 * b + std::pow( b * b - 4 * a * c, .5 ) ) / ( 2 * a );
	long double t2 = ( -1 * b - std::pow( b * b - 4 * a * c, .5 ) ) / ( 2 * a );
	Point* i1 = new Point( l.getX() + alpha * t1, l.getY() + beta * t1, l.getZ() + gamma * t1 );
	Point* i2 = new Point( l.getX() + alpha * t2, l.getY() + beta * t2, l.getZ() + gamma * t2 );
	if( t1 > 0 ) {	// t is greater than 0 when going in the right direction
		if( t2 > 0 ) {	// both are in the right direction, compare distances
			if( t1 <= t2 ) {
				return i1;
			}
			return i2;	//i1 was further
		}
		return i1;	// i1 was only valid solution
	}
	if( t2 > 0 ) {	
		return i2;	// i2 is only valid solution;
	}
	return nullptr;	// Return null pointer
}
std::pair<Point, Point>* Sphere::getIntersections( Line &l ) {	// http://www.ambrsoft.com/TrigoCalc/Sphere/SpherLineIntersection_.htm
    long double alpha = l.getDX();
    long double beta = l.getDY();
    long double gamma = l.getDZ();
    long double a = alpha * alpha + beta * beta + gamma * gamma;
    long double b = -2 * ( alpha * ( getX() - l.getX() ) + beta * ( getY() - l.getY() ) + gamma * ( getZ() - l.getZ() ) );
    long double c = std::pow( ( getX() - l.getX() ), 2 ) + std::pow( ( getY() - l.getY() ), 2 ) + std::pow( ( getZ() - l.getZ() ), 2 ) - r * r;

    if( ( b * b - 4 * a * c ) < 0 ) {
        return nullptr;
    }

    long double t1 = ( -1 * b + std::pow( b * b - 4 * a * c, .5 ) ) / ( 2 * a );
    long double t2 = ( -1 * b - std::pow( b * b - 4 * a * c, .5 ) ) / ( 2 * a );
    Point i1( l.getX() + alpha * t1, l.getY() + beta * t1, l.getZ() + gamma * t1 );
    Point i2( l.getX() + alpha * t2, l.getY() + beta * t2, l.getZ() + gamma * t2 );
    std::pair<Point, Point>* intersections = new std::pair<Point, Point>(i1, i2);
    return intersections;
}
Vector* Sphere::getNormal( Point &p ) {	
	return new Vector( p.getX() - getX(), p.getY() - getY(), p.getZ() - getZ() );	// Use gradient to determine normal
}
Plane::Plane() {
    setX(0);
    setY(0);
    setZ(0);
    setDX(0);
    setDY(0);
    setDZ(0);
}
Plane::Plane(long double nx, long double ny, long double nz, long double ndx, long double ndy, long double ndz) {
    setX(nx);
    setY(ny);
    setZ(nz);
    setDX(ndx);
    setDY(ndy);
    setDZ(ndz);
}
Geometry::Point* Plane::getIntersection(Geometry::Line &l) {
    if(getDotProduct(l)==0) {  // 90 degree angle between normal and direction. Ignore parallel case.
        return nullptr;
    }
    long double t = getDX()*(getX()-l.getX()) + getDY()*(getY()-l.getY()) + getDZ()*(getZ()-l.getZ());
    t /= (getDX()*l.getDX() + getDY()*l.getDY() + getDZ()*l.getDZ());

    Geometry::Point* p = new Geometry::Point(getX()+getDX()*t, getY()+getDY()*t, getZ()+getDZ());
    return p;
}