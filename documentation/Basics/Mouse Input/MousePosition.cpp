#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

class Cursor : public RectRenderObject
{
  public:
    void Start() override { SetFillColor(255, 0, 0, 255); }

    void Update(double deltaTime) override
    {
        SetPosition(game->GetMousePosition().x - 50, game->GetMousePosition().y - 50);
    }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<Cursor>());

    return game->Run();
}
