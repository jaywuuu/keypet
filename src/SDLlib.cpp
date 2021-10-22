#include "SDLlib.h"
#include <SDL_image.h>
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

/* SDLImg */
SDLImg &SDLImg::get(int flags) {
  static SDLImg instance{flags};
  return instance;
}

SDLImg::SDLImg(int flags) {
  if (IMG_Init(flags) == 0)
    throw std::runtime_error("Error initializing SDL Image.");
}

SDLImg::~SDLImg() { IMG_Quit(); }

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

/* SDLShapedWindow */
SDLShapedWindow::SDLShapedWindow(const char *name, int x, int y, int width,
                                 int height, uint32_t flags)
    : Window(nullptr) {
  Window = SDL_CreateShapedWindow(name, x, y, width, height, flags);
  if (!Window)
    throw std::runtime_error("Failed to create SDL Window.");
}

SDLShapedWindow::~SDLShapedWindow() {
  if (Window)
    SDL_DestroyWindow(Window);
}

SDL_Window *SDLShapedWindow::get() { return Window; }

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

/* SDLSurface */
SDLSurface::SDLSurface(const char *fileName) : Surface(nullptr) {
  Surface = IMG_Load(fileName);
  if (!Surface)
    throw std::runtime_error(std::string("Failed to load surface from ") +
                             fileName);
}

SDLSurface::~SDLSurface() {
  if (Surface)
    SDL_FreeSurface(Surface);
}

SDL_Surface *SDLSurface::get() { return Surface; }

/* SDLTexture */
SDLTexture::SDLTexture(SDL_Renderer *renderer, const char *fileName)
    : Texture(nullptr), Name(fileName) {
  Texture = IMG_LoadTexture(renderer, fileName);
  if (!Texture)
    throw std::runtime_error(std::string("Failed to load texture from ") +
                             fileName);

  Info = {0};

  if (SDL_QueryTexture(Texture, &Info.format, &Info.access, &Info.width,
                       &Info.height))
    throw std::runtime_error(std::string("Failed to query texture info from ") +
                             Name);
}

SDLTexture::SDLTexture(SDL_Renderer *renderer, SDL_Surface *surface)
    : Texture(nullptr) {
  Texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (!Texture)
    throw std::runtime_error("Failed to load texture from surface.");

  Info = {0};

  if (SDL_QueryTexture(Texture, &Info.format, &Info.access, &Info.width,
                       &Info.height))
    throw std::runtime_error("Failed to query texture info from surface.");
}

SDLTexture::~SDLTexture() {
  if (Texture)
    SDL_DestroyTexture(Texture);
}

SDL_Texture *SDLTexture::get() { return Texture; }
int SDLTexture::getWidth() const { return Info.width; }
int SDLTexture::getHeight() const { return Info.height; }

} // namespace KeyPet