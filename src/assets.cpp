#include "assets.h"
#include "SDLlib.h"
#include "pet.h"

#include <fstream>
#include <iostream>
#include <json.hpp>
#include <sstream>

using namespace KeyPet;

namespace KeyPet {

void loadAssets(SDL_Renderer *renderer, Pet &pet, const char *file) {
  std::ifstream input(file, std::ifstream::in);
  if (!input.is_open()) {
    throw std::runtime_error(std::string("Error opening file: ") + file);
  }

  std::string dirPath(file);
  std::string::size_type pos = dirPath.rfind('/');
  if (pos != std::string::npos)
    dirPath = dirPath.substr(0, pos);

  std::stringstream jsonStr;
  jsonStr << input.rdbuf();

  nlohmann::json j = nlohmann::json::parse(jsonStr.str());
  std::cout << "Animations: " << std::endl;
  for (auto &a : j["animations"]) {
    std::cout << "Name: " << a["name"] << std::endl;
    Animation anim = {};
    anim.name = a["name"];
    anim.numFrames = a["numFrames"];
    anim.delay = a["delay"];

    std::cout << "Loading textures..." << std::endl;
    for (auto &f : a["frames"]) {
      std::cout << dirPath << "/" << f << std::endl;
      std::string texturePath = dirPath + "/" + std::string(f);
      SDLTexture *tex = pet.addTexture(renderer, texturePath.c_str());
      anim.frames.push_back(tex);
    }

    pet.setAnimation(a["type"], anim);
  }
}

} // namespace KeyPet