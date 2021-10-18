#ifndef __SDL_LIB_H__
#define __SDL_LIB_H__

#include <SDL.h>

namespace KeyPet {

class SDL {
public:
  SDL(uint32_t flags);
  ~SDL();
};

} // namespace KeyPet

#endif /* __SDL_LIB_H__ */