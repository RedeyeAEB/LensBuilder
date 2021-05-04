#ifndef OPTICASSEMBLY_H
#define OPTICASSEMBLY_H

#include <vector>
#include "optic.h"

class OpticAssembly : public std::vector<Optic::Optic> {
};
class LensAssembly : public std::vector<Optic::Lens> {
};
#endif
