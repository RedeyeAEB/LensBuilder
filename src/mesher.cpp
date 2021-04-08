#include "mesher.h"
#include <vector>
#include <cmath>

#pragma message ("mesher.cpp: using compile-time tesselation values")
#define tesscoef 120    // Splits per 2pi radians
#define PI 3.1415926535897932384626433832795028841971   // 40 digits
#pragma message ("mesher.cpp: incomplete code - generates single optic of type biconvex only")

std::vector<glm::vec3> mesher::getFaces(std::vector<glm::vec3> &accum, Optic::Lens o) {    // Generates lens on z axis, front down
    //std::vector<glm::vec3> accum;   // Points vector to return

    // Generate transformation matrix for each point
    Geometry::Line axis = o.getAxis();  // https://learnopengl.com/Getting-started/Transformations
    glm::mat4 trans = glm::mat4(1.0f);
    Geometry::Vector zhat = Geometry::Vector(0,0,1);
    trans = glm::rotate(trans, (float)axis.getTheta(), axis.getCrossProduct(zhat).getUnitVector().glmvec3());

    // First generate the edge thickness, if it's 0, there's just going to be a ring of points
    // If it's not 0, it'll make a 2D ring of points for the edge

    long double r = o.getRadius();    // Radius of glass, if not limited by the following 3 vars.
    long double rf = o.getRadiusFront();   // Radius of front
    long double rb = o.getRadiusBack();    // Radius of back
    long double t = o.getThickness(); // Thickness

    long double x = (t * t - 2 * t * rb) / (2 * (t - rb - rf));
    long double rint = std::sqrt(rf * rf - (x - rf) * (x - rf));    // Calculated radius of intersection
    if (rint > r) {    // Generate edge if the intersection radius is greater than lens rad
        // First calculate the thickness of the edge
        long double xf = rf - sqrt(rf * rf - r * r);
        long double xb = sqrt(rb * rb - r * r) - rb + t;
        long double et = xb - xf;  // Edge thickness
        long double lastX = r;   // cos(0)*r = r
        long double lastY = 0;  // sin(0)*r = 0
        for (long double i = 1; i <= tesscoef; i++) {   // long double to force autocast on divide
            // Get X and Y of current ring section
            long double currentX = r * cos(2 * PI * i / tesscoef);    // Generate current x & y position;
            long double currentY = r * sin(2 * PI * i / tesscoef);
            // Generate the back-side vertex, clockwise
            // accum.push_back(lastX); // x    v1  t1
            // accum.push_back(lastY); // y
            // accum.push_back(xb);    // z
            accum.push_back(glm::vec3(trans*glm::vec4(lastX, lastY, xb,0)));
            //std::cout<< lastX << "\t" << lastY << "\t" << xb << std::endl;
            // accum.push_back(lastX); // x    v2
            // accum.push_back(lastY); // y
            // accum.push_back(xf);    // z
            accum.push_back(glm::vec3(trans*glm::vec4(lastX, lastY, xf, 0)));
            //std::cout<< lastX << "\t" << lastY << "\t" << xf << std::endl;
            // accum.push_back(currentX);  // x    v3
            // accum.push_back(currentY);  // y
            // accum.push_back(xf);        // z
            accum.push_back(glm::vec3(trans*glm::vec4(currentX, currentY, xf,0)));
            //std::cout<< currentX << "\t" << currentY << "\t" << xf << std::endl;
            // Generate the front-side vertex, clockwise
            // accum.push_back(lastX);
            // accum.push_back(lastY);
            // accum.push_back(xb);
            accum.push_back(glm::vec3(trans*glm::vec4(lastX, lastY, xb, 0)));
            //std::cout<< lastX << "\t" << lastY << "\t" << xb << std::endl;
            // accum.push_back(currentX);
            // accum.push_back(currentY);
            // accum.push_back(xf);
            accum.push_back(glm::vec3(trans*glm::vec4(currentX, currentY, xf, 0)));
            //std::cout<< currentY << "\t" << currentX << "\t" << xf << std::endl;
            // accum.push_back(currentX);
            // accum.push_back(currentY);
            // accum.push_back(xb);
            accum.push_back(glm::vec3(trans*glm::vec4(currentX, currentY, xb, 0)));
            //std::cout<< currentX << "\t" << currentY << "\t" << xb << std::endl;

            lastX = currentX;
            lastY = currentY;
        }


    } else {    // If it gets here, it means the lens is smaller than the defined radius.
        r = rint;   // Reset local r variable to actual rendered radius.
    }
    // Generate front surface to radius of intersection, semi-UV style


        return accum;
}