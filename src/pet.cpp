#include "pet.h"

#include <stdexcept>

using namespace KeyPet;

namespace KeyPet {

Pet::Pet(const char *name, const char *file)
    : Name(name), BaseSurface(file), Speed(0), CurrentAnimation(0) {}

SDLSurface &Pet::getBaseSurface() { return BaseSurface; }

SDLTexture *Pet::createBaseTexture(SDL_Renderer *renderer) {
  BaseTexture = std::make_unique<SDLTexture>(renderer, BaseSurface.get());
  return BaseTexture.get();
}

SDLTexture *Pet::getBaseTexture() { return BaseTexture.get(); }

SDLTexture *Pet::addTexture(SDL_Renderer *renderer, const char *file) {
  Textures.push_back(std::make_unique<SDLTexture>(renderer, file));
  return Textures[Textures.size() - 1].get();
}

Animation &Pet::getAnimation(int index) {
  if (index < 0 || index >= Animations.size())
    throw std::runtime_error("Index out of bounds for animation.");

  return Animations[index];
}

void Pet::setAnimation(int index, Animation &anim) {
  if (index >= Animations.size()) {
    for (auto i = Animations.size(); i < index; ++i) {
      Animation a = {0};
      Animations.push_back(a);
    }
    Animations.push_back(anim);
  } else {
    Animations[index] = anim;
  }
}

int Pet::getCurrentAnimationIndex() const { return CurrentAnimation; }

} // namespace KeyPet