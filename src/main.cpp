#include "SDLlib.h"
#include "display.h"
#include "event.h"
#include "render.h"
#include "types.h"

#include <SDL_image.h>

using namespace KeyPet;

int main(int argc, char *argv[]) {
  const char *AppName = "KeyPet";

  /* init SDL, window, and renderer */
  SDL &sdl = SDL::get(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
  SDLImg &sdlImg = SDLImg::get(IMG_INIT_PNG);

  Rect screenSize = getCurrentScreenSize(0);
  const int width = 640;
  const int height = 480;
  const int x = screenSize.width - width;
  const int y = (screenSize.height - height) / 2;

  uint32_t winFlags = (SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP);
  SDLWindow window{AppName, x, y, width, height, winFlags};
  SDLRenderer renderer{window.get(), -1, SDL_RENDERER_ACCELERATED};

  SDLTexture uchan{renderer.get(),
                   "data/sprites/unitychan/Unitychan_Idle_1.png"};

  /* main loop */
  Context ctx = {};
  bool loop = true;
  while (loop) {

    render(renderer);

    SDL_Rect dstRect = {width / 2, height / 2, uchan.getWidth(),
                        uchan.getHeight()};
    SDL_RenderCopy(renderer.get(), uchan.get(), nullptr, &dstRect);

    int signal = eventHandler(&ctx);
    if (signal == EventSignal_Quit)
      break;

    present(renderer);

    SDL_Delay(16); // assume 60 fps
  }

  return 0;
}