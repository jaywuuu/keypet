#include "SDLlib.h"
#include <iostream>

using namespace KeyPet;

int main(int argc, char *argv[]) {
  std::cout << "Starting SDL...\n";

  SDL &sdl = SDL::get(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
  SDLWindow window{"KeyPet", 0, 0, 640, 480, SDL_WINDOW_BORDERLESS};
  SDLRenderer renderer{window.get(), -1, SDL_RENDERER_ACCELERATED};

  bool loop = true;
  while (loop) {

    SDL_SetRenderDrawColor(renderer.get(), 96, 128, 255, 255);
    SDL_RenderClear(renderer.get());

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        exit(0);
        break;

      default:
        break;
      }
    }

    SDL_RenderPresent(renderer.get());

    SDL_Delay(16); // assume 60 fps
  }

  return 0;
}