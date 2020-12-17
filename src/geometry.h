#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>

namespace Geometry {
	class Point {
		private:
			long double x;
			long double y;
			long double z;
		public:
			Point();
			Point( long double nx, long double ny, long double nz );
		 	long double getX();
			long double getY();
			long double getZ();
			long double setX( long double nx );
			long double setY( long double ny );
			long double setZ( long double nz );
			long double getDistance( Point &p );
	};
	class Vector {
		private:
			long double dx;
			long double dy;
			long double dz;
		public:
			Vector();
			Vector( long double ndx, long double ndy, long double ndz );
			long double getDX();
			long double getDY();
			long double getDZ();
			long double setDX( long double ndx );
			long double setDY( long double ndy );
			long double setDZ( long double ndz );
			long double setR( long double nr );
			long double setTheta( long double nTheta );
			long double setPhi( long double nPhi );
			long double getR();
			long double getTheta();
			long double getPhi();
	};
	class Line: public Point, public Vector {
		public:
			Line();
			Line( long double nx, long double ny, long double nz, long double ndx, long double ndy, long double ndz );
			Line( Point &np, long double ndx, long double ndy, long double ndz );
			Line( Point &np, Vector &nd );
			Line( Point &a, Point &b );
	};
	class Sphere: public Point {
		private:
			long double r;
		public:
			Sphere( long double x, long double y, long double z, long double r );
			Sphere( Point &p, long double r );
			long double getR();
			long double setR( long double nr );
			bool containsPoint( Point &p );
			Point* getIntersection( Line &l );
			Vector* getNormal( Point &p );
	};
}	

#endif