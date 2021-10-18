#include "SDLlib.h"
#include <stdexcept>

namespace KeyPet {

/* SDLlib */
SDL &SDL::get(uint32_t flags) {
  static SDL instance{flags};
  return instance;
}

SDL::SDL(uint32_t flags) {
  if (SDL_Init(flags))
    throw std::runtime_error("Error initializing SDL.");
}

SDL::~SDL() { SDL_Quit(); }

/* SDLWindow */
SDLWindow::SDLWindow(const char *name, int x, int y, int width, int height,
                     uint32_t flags)
    : Window(nullptr) {
  Window = SDL_CreateWindow(name, x, y, width, height, flags);
  if (!Window)
    throw std::runtime_error("Failed to create SDL Window.");
}

SDLWindow::~SDLWindow() {
  if (Window)
    SDL_DestroyWindow(Window);
}

SDL_Window *SDLWindow::get() { return Window; }

/* SDLRenderer */
SDLRenderer::SDLRenderer(SDL_Window *Win, int index, uint32_t flags)
    : Window(Win), Renderer(nullptr) {
  Renderer = SDL_CreateRenderer(Win, index, flags);
  if (!Renderer)
    throw std::runtime_error("Failed to create SDL Renderer.");
}
SDLRenderer::~SDLRenderer() {
  if (Renderer)
    SDL_DestroyRenderer(Renderer);
}

SDL_Renderer *SDLRenderer::get() { return Renderer; }

} // namespace KeyPet