#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>

#include <glm/glm.hpp>

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
			long double getMagnitude(); // Same thing as getR()
			long double getTheta();
			long double getPhi();

            Vector getUnitVector();
			long double getDotProduct( Vector &o );
			Vector getCrossProduct( Vector &o );

			long double getAngleBetween( Vector &o );

			// https://en.wikipedia.org/wiki/Rodrigues'_rotation_formula
            Vector rotateVectorRadians(Vector &rotateAxis, long double radians);
            //Vector rotateVectorDegrees(Vector &rotateAxis, long double degrees);

			glm::vec3 glmvec3();
	};
	class Line: public Point, public Vector {
		public:
			Line();
			Line( long double nx, long double ny, long double nz, long double ndx, long double ndy, long double ndz );
			Line( Point &np, long double ndx, long double ndy, long double ndz );
			Line( Point &np, Vector &nd );
			Line( Point &a, Point &b );
	};
	class Sphere: public Point {    // Negative radii are properly encoded, positive bulges left
		private:
			long double r;
		public:
			Sphere( long double x, long double y, long double z, long double r );
			Sphere( Point &p, long double r );
			long double getR();
			long double setR( long double nr );
			bool containsPoint( Point &p );
			Point* getIntersection( Line &l );
			std::pair<Point, Point>* getIntersections(Line &I);
			Vector* getNormal( Point &p );
	};
    class Plane: public Line {
    // No privates required - the coordinate and normal are encoded in the public Line
    public:
        Plane();
        Plane(long double x, long double y, long double z, long double dx, long double dy, long double dz);
        Geometry::Point* getIntersection(Geometry::Line &l); // Return nullptr if no intersection, Point if intersection

    };
}

#endif