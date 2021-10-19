#include "event.h"
#include <SDL.h>

using namespace KeyPet;

namespace KeyPet {
int eventHandler(Context *ctx) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      return EventSignal_Quit;
      break;

    default:
      break;
    }
  }

  return EventSignal_None;
}
} // namespace KeyPet