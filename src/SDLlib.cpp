#include "SDLlib.h"
#include <stdexcept>

namespace KeyPet {

SDL::SDL(uint32_t flags) {
  if (SDL_Init(flags))
    throw std::runtime_error("Error initializing SDL.");
}

SDL::~SDL() { SDL_Quit(); }

} // namespace KeyPet