#ifndef OPTIC_H
#define OPTIC_H

#include <iostream>
#include "light.h"

namespace Optic {
	class Optic {	// The 'interface'
		private:
			Geometry::Line axis;    // First point encodes the position
		public:
			Light::Ray getPath( Light::Ray &r );
			Geometry::Point getPosition();
			Geometry::Point setPosition( Geometry::Point &p );
			Geometry::Line getAxis();
			Geometry::Line setAxis( Geometry::Line &na );
	};
	class Lens : public Optic {
		private: 
			long double radius;
			Geometry::Sphere* s1;
			Geometry::Sphere* s2;
			long double thickness;
			long double index;
		public:
			Lens( Geometry::Line &na, long double nr, long double nt, long double nfrontr, long double nbackr, long double n1 );
	        long double getRadius();
	        long double getThickness();
	        long double getIndex();
	        Geometry::Sphere getFront();
	        Geometry::Sphere getBack();
	        long double getRadiusFront();
	        long double getRadiusBack();
	};
	/*class Mirror : Optic {
		private:
			long double radius;
			Geometry::Sphere s;
		public:

	};*/
}

#endif