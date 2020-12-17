#include "interface.h"
#include <gtkmm/application.h>

int main( int argc, char *argv[] ) {
  auto app = Gtk::Application::create( argc, argv, "LensBuilder" );

  Interface interface;

  return app->run(interface);
}



/*#include <iostream>
#include "geometry.h"
using namespace Geometry;

int main() {
	Sphere lensSim( 0, 0, 0, 1 );
	Line raySim( 1, 1, 2, -1, -1, -1 );

	Point* p = lensSim.getIntersection( raySim );
	std::cout << p;
	std::cout << "Done!";
}*/