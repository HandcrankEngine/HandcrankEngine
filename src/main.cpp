#define HANDCRANK_DEBUG 1

#include "Handcrank/Handcrank.hpp"

#include "../examples/animation/AnimatedBorder.hpp"
#include "../examples/fps/FPS.hpp"
#include "../examples/logo-screensaver/LogoScreenSaver.hpp"
#include "../examples/paused-screen/PausedScreen.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

class InputManager : public RenderObject
{
  public:
    void Update(const double deltaTime) override
    {
        if (game->IsKeyPressed(SDLK_ESCAPE))
        {
            game->Quit();
        }
        else if (game->IsKeyPressed(SDLK_d))
        {
            game->ToggleDebug();
        }
    }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<InputManager>()));
    game->AddChildObject(std::move(std::make_unique<LogoScreenSaver>()));
    game->AddChildObject(std::move(std::make_unique<FPS>()));
    game->AddChildObject(std::move(std::make_unique<AnimatedBorder>()));
    game->AddChildObject(std::move(std::make_unique<PausedScreen>()));

    return game->Run();
}
