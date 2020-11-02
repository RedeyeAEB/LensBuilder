#include <iostream>
#include "geometry.h"

namespace Light {
	class Ray : Geometry::Line {
		private:
			long double wavelength;	// In nanometers
		public:
			Ray();
			Ray( long double nwl );
			Ray( long double nx, long double ny, long double nz, long double ndx, long double ndy, long double ndz, long double nwl );
			Ray( long double nx, long double ny, long double nz, long double nTheta, long double nPhi, long double nwl );	// R doesn't matter, removed here to allow for differenciation between this and the dxdydz case.
			Ray( Point c, Vector d, long double nwl );
			long double setWavelength( long double nwl );
			long double getWavelength();
	};
}