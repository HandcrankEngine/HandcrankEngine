#include "../images/sdl_logo.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/ImageRenderObject.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

class SDL_Logo : public ImageRenderObject
{
  public:
    void Start() override
    {
        LoadTexture(game->GetRenderer(), images_sdl_logo_png,
                      images_sdl_logo_png_len);
    }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<SDL_Logo>());

    return game->Run();
}
