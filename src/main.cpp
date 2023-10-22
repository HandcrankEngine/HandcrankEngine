#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = new Game();

class ExampleRect : public RectRenderObject
{

    void Start() override
    {
        SetRect(0, 0, 100, 100);

        SetFillColor({255, 0, 0, 255});
    }

    void Update(double deltaTime) override { rotation += 100 * deltaTime; }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<ExampleRect>()));

    return game->Run();
}
