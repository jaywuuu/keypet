#ifndef __pet_h__
#define __pet_h__

#include "SDLlib.h"
#include "assets.h"

#include <memory>
#include <string>

namespace KeyPet {

class Pet {
public:
  enum AnimationIndex { AnimIdle = 0 };

public:
  Pet(const char *name, const char *file);

  Pet(const Pet &) = delete;            // delete copy
  Pet &operator=(const Pet &) = delete; // delete copy assignment

  SDLSurface &getBaseSurface();
  SDLTexture *createBaseTexture(SDL_Renderer *renderer);
  SDLTexture *getBaseTexture();

  SDLTexture *addTexture(SDL_Renderer *renderer, const char *file);

  Animation &getAnimation(int index);
  void setAnimation(int index, Animation &anim);

  int getCurrentAnimationIndex() const;

private:
  SDLSurface BaseSurface;
  std::unique_ptr<SDLTexture> BaseTexture;
  int Speed;
  std::string Name;
  std::vector<std::unique_ptr<SDLTexture>> Textures;
  std::vector<Animation> Animations;
  int CurrentAnimation;
};

} // namespace KeyPet

#endif /* __pet_h__ */