#include "Handcrank/Handcrank.hpp"

#include "../examples/box/Box.hpp"
#include "../examples/fps/FPS.hpp"
#include "../examples/logo-screensaver/LogoScreenSaver.hpp"

using namespace Handcrank;

auto game = new Game();

class InputManager : public RenderObject
{
  public:
    void Update(const double deltaTime) override
    {
        if (game->keyState[SDLK_ESCAPE])
        {
            game->Quit();
        }
    }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<Box>()));
    game->AddChildObject(std::move(std::make_unique<FPS>()));
    game->AddChildObject(std::move(std::make_unique<InputManager>()));
    game->AddChildObject(std::move(std::make_unique<LogoScreenSaver>()));

    return game->Run();
}
