#define HANDCRANK_DEBUG 1

#include "Handcrank/Handcrank.hpp"

#include "../examples/animation/AnimatedBorder.hpp"
#include "../examples/fps/FPS.hpp"
#include "../examples/logo-screensaver/LogoScreenSaver.hpp"
#include "../examples/paused-screen/PausedScreen.hpp"
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
        else if (game->keyPressedState[SDLK_d])
        {
            game->ToggleDebug();
        }
    }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    auto spawner = std::make_shared<Spawner>();

    game->AddChildObject(std::move(std::make_unique<InputManager>()));
    game->AddChildObject(spawner);
    game->AddChildObject(std::move(std::make_unique<FPS>()));
    game->AddChildObject(std::move(std::make_unique<AnimatedBorder>()));
    game->AddChildObject(std::move(std::make_unique<PausedScreen>()));

    for (auto i = 0; i < 1; i += 1)
    {
        spawner->AddChildObject(std::move(std::make_unique<LogoScreenSaver>()));
    }

    return game->Run();
}
