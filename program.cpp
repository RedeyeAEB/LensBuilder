#include <iostream>
#include "src/geometry.h"

using namespace Geometry;

int main() {
	Sphere lensSim( 0, 0, 0, 1 );
	Line raySim( 1, 1, 2, -1, -1, -1 );

	Point* p = lensSim.getIntersection( raySim );
	std::cout << "Done!";
} 