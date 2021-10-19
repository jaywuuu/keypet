#include "display.h"
#include <SDL.h>
#include <stdexcept>

using namespace KeyPet;

namespace KeyPet {

Rect getCurrentScreenSize(int displayIndex) {
  Rect size = {0};
  SDL_DisplayMode mode = {0};

  if (SDL_GetCurrentDisplayMode(displayIndex, &mode) != 0)
    throw std::runtime_error("Call to SDL_GetCurrentDisplayMode failed.");

  size.width = mode.w;
  size.height = mode.h;

  return size;
}
} // namespace KeyPet
