#include "pet.h"

using namespace KeyPet;

namespace KeyPet {

Pet::Pet(const char *name, const char *file)
    : Name(name), BaseSurface(file), Speed(0) {}

SDLSurface &Pet::getBaseSurface() { return BaseSurface; }

SDLTexture *Pet::createBaseTexture(SDL_Renderer *renderer) {
  BaseTexture = std::make_unique<SDLTexture>(renderer, BaseSurface.get());
  return BaseTexture.get();
}

SDLTexture *Pet::getBaseTexture() { return BaseTexture.get(); }

} // namespace KeyPet