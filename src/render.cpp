#include "render.h"

#include <SDL.h>

using namespace KeyPet;

namespace KeyPet {

void render(Context &context, SDLRenderer &renderer) {
  SDLTexture &pet = context.pet;
  SDL_Rect dstRect = {0, 0, pet.getWidth(), pet.getHeight()};
  SDL_RenderCopy(renderer.get(), pet.get(), nullptr, &dstRect);
}

void present(SDLRenderer &renderer) { SDL_RenderPresent(renderer.get()); }

} // namespace KeyPet