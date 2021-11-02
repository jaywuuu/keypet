#include "render.h"

#include <SDL.h>

using namespace KeyPet;

namespace KeyPet {

void render(Context &context, SDLRenderer &renderer) {
  Pet &pet = context.pet;
  int animIndex = pet.getCurrentAnimationIndex();

  Animation &anim = pet.getAnimation(animIndex);
  if (anim.currentFrame >= anim.numFrames)
    anim.currentFrame = 0;

  SDLTexture *petTexture = anim.frames[anim.currentFrame];
  SDL_Rect dstRect = {0, 0, petTexture->getWidth(), petTexture->getHeight()};
  SDL_RendererFlip flip = context.flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
  SDL_RenderCopyEx(renderer.get(), petTexture->get(), nullptr, &dstRect, 0, 0,
                   flip);

  anim.currentFrame++;
}

void present(SDLRenderer &renderer) { SDL_RenderPresent(renderer.get()); }

void clear(SDLRenderer &renderer) { SDL_RenderClear(renderer.get()); }

} // namespace KeyPet