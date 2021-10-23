#ifndef __pet_h__
#define __pet_h__

#include "SDLlib.h"

#include <memory>
#include <string>


namespace KeyPet {

class Pet {
public:
  Pet(const char *name, const char *file);

  Pet(const Pet &) = delete;            // delete copy
  Pet &operator=(const Pet &) = delete; // delete copy assignment

  SDLSurface &getBaseSurface();
  SDLTexture *createBaseTexture(SDL_Renderer *renderer);
  SDLTexture *getBaseTexture();

private:
  SDLSurface BaseSurface;
  std::unique_ptr<SDLTexture> BaseTexture;
  int Speed;
  std::string Name;
};

} // namespace KeyPet

#endif /* __pet_h__ */