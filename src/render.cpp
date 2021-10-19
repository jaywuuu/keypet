#include "render.h"

#include <SDL.h>

using namespace KeyPet;

namespace KeyPet {

void render(SDLRenderer &renderer) {
  SDL_SetRenderDrawColor(renderer.get(), 96, 128, 255, 255);
  SDL_RenderClear(renderer.get());
}

void present(SDLRenderer &renderer) { SDL_RenderPresent(renderer.get()); }

} // namespace KeyPet