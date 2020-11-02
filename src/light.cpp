#include <iostream>
#include "geometry.h"
#include "light.h"
using namespace Light;

Ray::Ray() {
	wavelength = 0;
}
Ray::Ray( long double nwl ) {
	wavelength = nwl;
}
Ray::Ray( long double nx, long double ny, long double nz, long double ndx, long double ndy, long double ndz, long double nwl ) {
	setX( nx );
	setY( ny );
	setZ( nz );
	setDX( ndx );
	setDY( ndy );
	setDZ( ndz );
	wavelength = nwl;
}
Ray::Ray( long double nx, long double ny, long double nz, long double nTheta, long double nPhi, long double nwl ) {
	setX( nx );
	setY( ny );
	setZ( nz );
	setR( 1 );
	setTheta( nTheta );
	setPhi( nPhi );
	wavelength = nwl;
}
Ray::Ray( Point c, Vector d, long double nwl ) {
	setX( c.getX() );
	setY( c.getY() );
	setZ( c.getZ() );
	setDX( d.getDX() );
	setDY( d.getDY() );
	setDZ( d.getDZ() );
	wavelength = nwl;
}
long double Ray::setWavelength( long double nwl ) {
	long double old = wavelength;
	wavelength = nwl;
	return old;
}
long double Ray::getWavelength() {
	return wavelength;
}