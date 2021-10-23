#include "render.h"

#include <SDL.h>

using namespace KeyPet;

namespace KeyPet {

void render(Context &context, SDLRenderer &renderer) {
  SDLTexture &pet = context.pet;
  SDL_Rect dstRect = {0, 0, pet.getWidth(), pet.getHeight()};
  SDL_RendererFlip flip = context.flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
  SDL_RenderCopyEx(renderer.get(), pet.get(), nullptr, &dstRect, 0, 0, flip);
}

void present(SDLRenderer &renderer) { SDL_RenderPresent(renderer.get()); }

} // namespace KeyPet