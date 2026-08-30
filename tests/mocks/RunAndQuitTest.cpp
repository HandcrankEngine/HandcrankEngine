#include "HandcrankEngine/HandcrankEngine.hpp"

using namespace HandcrankEngine;

class QuitDemo : public RenderObject
{
  public:
    void Update(double deltaTime) override { game->Quit(); }
};

auto main(int argc, char *argv[]) -> int
{
    auto game = std::make_unique<Game>();

    game->SetTitle("Run and Quit Test");

    game->AddChildObject(std::make_shared<QuitDemo>());

    return game->Run();
}
