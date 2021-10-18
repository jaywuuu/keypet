#ifndef __SDL_LIB_H__
#define __SDL_LIB_H__

#include <SDL.h>

namespace KeyPet {

class SDL {
public:
  static SDL &get(uint32_t flags = 0);
  ~SDL();

private:
  SDL(uint32_t flags);

public:
  SDL(SDL const &) = delete;
  void operator=(SDL const &) = delete;
};

class SDLWindow {
public:
  SDLWindow(const char *name, int x, int y, int width, int height,
            uint32_t flags);
  ~SDLWindow();

  // for now let's just delete copy and move.
  SDLWindow(const SDLWindow &) = delete;            // delete copy
  SDLWindow &operator=(const SDLWindow &) = delete; // delete assignment
  SDLWindow(SDLWindow &&) = delete;                 // delete move
  SDLWindow &operator=(SDLWindow &&) = delete;      // delete assignment move

private:
  SDL_Window *Window;

public:
  SDL_Window *get();
};

class SDLRenderer {
public:
  SDLRenderer(SDL_Window *Win, int index, uint32_t flags);
  ~SDLRenderer();

  // for now let's just delete copy and move.
  SDLRenderer(const SDLRenderer &) = delete;            // delete copy
  SDLRenderer &operator=(const SDLRenderer &) = delete; // delete assignment
  SDLRenderer(SDLRenderer &&) = delete;                 // delete move
  SDLRenderer &operator=(SDLRenderer &&) = delete; // delete assignment move

private:
  SDL_Window *Window;
  SDL_Renderer *Renderer;

public:
  SDL_Renderer *get();
};

} // namespace KeyPet

#endif /* __SDL_LIB_H__ */