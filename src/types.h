#ifndef __types_h__
#define __types_h__

#include "Pet.h"
#include "SDLlib.h"

namespace KeyPet {

struct Rect {
  int x;
  int y;
  int width;
  int height;
};

struct Context {
  Pet &pet;
  bool flip;
};

} // namespace KeyPet

#endif /* __types_h__ */