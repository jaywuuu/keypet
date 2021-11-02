#ifndef __assets_h__
#define __assets_h__

#include <string>
#include <vector>

struct SDL_Renderer;

namespace KeyPet {

class SDLTexture;
class Pet;

struct Animation {
  std::string name;
  int numFrames;
  int currentFrame;
  int delay;
  std::vector<SDLTexture *> frames;
};

void loadAssets(SDL_Renderer *renderer, Pet &pet, const char *file);

} // namespace KeyPet

#endif /* __assets_h__ */
