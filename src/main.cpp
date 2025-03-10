#include "Handcrank/Handcrank.hpp"

#include "../examples/fps/FPS.hpp"
#include "../examples/logo-screensaver/LogoScreenSaver.hpp"
#include "../examples/spawner/Spawner.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

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

    game->AddChildObject(std::move(std::make_unique<InputManager>()));
    game->AddChildObject(std::move(std::make_unique<Spawner>()));
    game->AddChildObject(std::move(std::make_unique<LogoScreenSaver>()));
    game->AddChildObject(std::move(std::make_unique<FPS>()));

    return game->Run();
}
