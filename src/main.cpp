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

        if (game->IsKeyPressed(SDLK_ESCAPE) || game->IsKeyPressed(SDLK_q))
        {
            game->Quit();
        }
        else if (game->IsKeyPressed(SDLK_d))
        {
            game->ToggleDebug();
        }
        else if (game->IsKeyDown(SDLK_LGUI) && game->IsKeyPressed(SDLK_f))
        {
            game->IsFullscreen() ? game->SwitchToWindowedMode()
                                 : game->SwitchToFullscreen();
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
