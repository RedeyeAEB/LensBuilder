#ifndef LENSBUILDER_MESHER_H
#define LENSBUILDER_MESHER_H
#include "optic.h"
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;


namespace mesher {
    std::vector<glm::vec3> getFaces(std::vector<glm::vec3> &v, Optic::Lens o);
};


#endif //LENSBUILDER_MESHER_H
