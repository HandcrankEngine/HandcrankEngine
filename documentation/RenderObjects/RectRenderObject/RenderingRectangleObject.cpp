#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    auto square = std::make_shared<RectRenderObject>();

    square->SetFillColor(255, 0, 0, 255);

    game->AddChildObject(square);

    return game->Run();
}
