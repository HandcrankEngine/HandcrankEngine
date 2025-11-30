#include "../images/sdl_logo.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/ImageRenderObject.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    auto image = std::make_shared<ImageRenderObject>();

    image->LoadTexture(game->GetRenderer(), images_sdl_logo_png,
                         images_sdl_logo_png_len);

    game->AddChildObject(image);

    return game->Run();
}
