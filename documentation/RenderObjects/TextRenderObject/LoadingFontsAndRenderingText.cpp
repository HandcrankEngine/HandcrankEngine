#include "../fonts/Roboto/Roboto-Regular.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/TextRenderObject.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    auto label = std::make_shared<TextRenderObject>();

    label->LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                      fonts_Roboto_Roboto_Regular_ttf_len, 30);

    label->SetText("Hello, World");

    game->AddChildObject(label);

    return game->Run();
}
