#define HANDCRANK_ENGINE_DEBUG 1

#include "HandcrankEngine/HandcrankEngine.hpp"

#include "../examples/animation/AnimatedBorder.hpp"
#include "../examples/fps/FPS.hpp"
#include "../examples/logo-screensaver/LogoScreenSaver.hpp"
#include "../examples/paused-screen/PausedScreen.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

class InputManager : public RenderObject
{
  public:
    void Update(double deltaTime) override
    {
        if (!game->HasFocus())
        {
            return;
        }

        if (game->IsKeyPressed(SDLK_ESCAPE) || game->IsKeyPressed(SDLK_Q))
        {
            game->Quit();
        }
        else if (game->IsKeyPressed(SDLK_D))
        {
            game->ToggleDebug();
        }
        else if (game->IsKeyDown(SDLK_LGUI) && game->IsKeyPressed(SDLK_F))
        {
            game->IsFullscreen() ? game->SwitchToWindowedMode()
                                 : game->SwitchToFullscreen();
        }
    }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<InputManager>());
    game->AddChildObject(std::make_shared<LogoScreenSaver>());
    game->AddChildObject(std::make_shared<FPS>());
    game->AddChildObject(std::make_shared<AnimatedBorder>());
    game->AddChildObject(std::make_shared<PausedScreen>());

    return game->Run();
}
