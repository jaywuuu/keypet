#include "SDLlib.h"
#include "display.h"
#include "event.h"
#include "pet.h"
#include "render.h"
#include "types.h"

#include <SDL_image.h>

using namespace KeyPet;

static SDL_HitTestResult HitTestCallback(SDL_Window *window,
                                         const SDL_Point *area, void *data) {
  return SDL_HITTEST_DRAGGABLE;
}

static void setupWindow(SDL_Window *window, SDL_Surface *surface) {
  SDL_WindowShapeMode mode = {};
  if (SDL_ISPIXELFORMAT_ALPHA(surface->format->format)) {
    mode.mode = ShapeModeBinarizeAlpha;
    mode.parameters.binarizationCutoff = 255;
  } else {
    mode.mode = ShapeModeColorKey;
    mode.parameters.colorKey = SDL_Color{0, 0, 0, 0};
  }

  SDL_SetWindowShape(window, surface, &mode);
  SDL_SetWindowHitTest(window, HitTestCallback, nullptr);
}

int main(int argc, char *argv[]) {
  const char *AppName = "KeyPet";

  /* init SDL, window, and renderer */
  SDL &sdl = SDL::get(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
  SDLImg &sdlImg = SDLImg::get(IMG_INIT_PNG);

  Rect screenSize = getCurrentScreenSize(0);

  Pet pet{"unity-chan", "data/sprites/unitychan/Unitychan_Idle_1.png"};
  SDLSurface &uchanSurf = pet.getBaseSurface();

  const int width = uchanSurf.get()->w;
  const int height = uchanSurf.get()->h;
  const int x = screenSize.width - width;
  const int y = (screenSize.height - height) / 2;

  uint32_t winFlags = (SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP);
  SDLShapedWindow window{AppName, x, y, width, height, winFlags};
  SDLRenderer renderer{window.get(), -1, SDL_RENDERER_ACCELERATED};

  setupWindow(window.get(), uchanSurf.get());

  pet.createBaseTexture(renderer.get());

  /* main loop */
  Context ctx = {pet};
  ctx.flip = false;

  bool loop = true;
  while (loop) {

    render(ctx, renderer);

    int signal = eventHandler(&ctx);
    if (signal == EventSignal_Quit)
      break;

    present(renderer);

    SDL_Delay(16); // assume 60 fps
  }

  return 0;
}