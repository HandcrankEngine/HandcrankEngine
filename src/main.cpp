#include "Handcrank/Handcrank.hpp"

#include "../examples/fps/FPS.hpp"
#include "../examples/logo-screensaver/LogoScreenSaver.hpp"

using namespace Handcrank;

auto game = new Game();

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<FPS>()));

    game->AddChildObject(std::move(std::make_unique<LogoScreenSaver>()));

    return game->Run();
}
