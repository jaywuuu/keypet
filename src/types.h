#ifndef __types_h__
#define __types_h__

#include "SDLlib.h"

namespace KeyPet {

struct Rect {
  int x;
  int y;
  int width;
  int height;
};

struct Context {
  SDLTexture &pet;
};

} // namespace KeyPet

#endif /* __types_h__ */