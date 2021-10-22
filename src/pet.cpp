#include "pet.h"

using namespace KeyPet;

namespace KeyPet {

Pet::Pet(const char *name, const char *file)
    : Name(name), BaseSurface(file), Speed(0) {}

SDLSurface &Pet::getBaseSurface() { return BaseSurface; }

} // namespace KeyPet