#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/SceneManager.hpp"

using namespace HandcrankEngine;

class LogosScene : public Scene
{
};

auto main() -> int
{
    auto game = std::make_unique<Game>();

    auto sceneManager = std::make_shared<SceneManager>();

    game->AddChildObject(sceneManager);

    sceneManager->AddScene(std::make_shared<LogosScene>());

    sceneManager->SetCurrentScene<LogosScene>();

    return game->Run();
}
