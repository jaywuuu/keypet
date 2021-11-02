#ifndef __SDL_lib_H__
#define __SDL_lib_H__

#include <SDL.h>
#include <string>

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

class SDLImg {
public:
  static SDLImg &get(int flags = 0);
  ~SDLImg();

private:
  SDLImg(int flags);

public:
  SDLImg(SDLImg const &) = delete;
  void operator=(SDLImg const &) = delete;
};

class SDLWindow {
public:
  SDLWindow(const char *name, int x, int y, int width, int height,
            uint32_t flags);
  ~SDLWindow();

  SDLWindow(const SDLWindow &) = delete;            // delete copy
  SDLWindow &operator=(const SDLWindow &) = delete; // delete copy assignment
  SDLWindow(SDLWindow &&) = default;                // default move
  SDLWindow &operator=(SDLWindow &&) = default;     // default move assignment

private:
  SDL_Window *Window;

public:
  SDL_Window *get();
};

class SDLShapedWindow {
public:
  SDLShapedWindow(const char *name, int x, int y, int width, int height,
                  uint32_t flags);
  ~SDLShapedWindow();

  SDLShapedWindow(const SDLShapedWindow &) = delete; // delete copy
  SDLShapedWindow &
  operator=(const SDLShapedWindow &) = delete;   // delete copy assignment
  SDLShapedWindow(SDLShapedWindow &&) = default; // default move
  SDLShapedWindow &
  operator=(SDLShapedWindow &&) = default; // default move assignment

private:
  SDL_Window *Window;

public:
  SDL_Window *get();
};

class SDLRenderer {
public:
  SDLRenderer(SDL_Window *Win, int index, uint32_t flags);
  ~SDLRenderer();

  SDLRenderer(const SDLRenderer &) = delete; // delete copy
  SDLRenderer &
  operator=(const SDLRenderer &) = delete; // delete copy assignment
  SDLRenderer(SDLRenderer &&R) {
    this->Window = R.Window;
    this->Renderer = R.Renderer;
    R.Renderer = nullptr;
    R.Window = nullptr;
  }

  SDLRenderer &operator=(SDLRenderer &&R) = delete; // delete move assignment

private:
  SDL_Window *Window;
  SDL_Renderer *Renderer;

public:
  SDL_Renderer *get();
};

class SDLSurface {
public:
  SDLSurface(const char *fileName);
  ~SDLSurface();

  SDLSurface(const SDLSurface &) = delete;            // delete copy
  SDLSurface &operator=(const SDLSurface &) = delete; // delete copy assignment
  SDLSurface(SDLSurface &&S) {
    this->Surface = S.Surface;
    S.Surface = nullptr;
  }

  SDLSurface &operator=(SDLSurface &&S) = delete; // delete move assignment

  SDL_Surface *get();

private:
  SDL_Surface *Surface;
};

class SDLTexture {
public:
  struct TextureInfo {
    uint32_t format;
    int access;
    int width;
    int height;
  };

  SDLTexture(SDL_Renderer *renderer, const char *fileName);
  SDLTexture(SDL_Renderer *renderer, SDL_Surface *surface);
  ~SDLTexture();

  SDLTexture(const SDLTexture &) = delete;            // delete copy
  SDLTexture &operator=(const SDLTexture &) = delete; // delete copy assignment
  SDLTexture(SDLTexture &&T) {
    this->Texture = T.Texture;
    T.Texture = nullptr;
    this->Info = T.Info;
  }
  SDLTexture &operator=(SDLTexture &&T) = delete; // delete move assignment

  SDL_Texture *get();
  int getWidth() const;
  int getHeight() const;

private:
  std::string Name;
  SDL_Texture *Texture;
  TextureInfo Info;
};

} // namespace KeyPet

#endif /* __SDL_lib_H__ */