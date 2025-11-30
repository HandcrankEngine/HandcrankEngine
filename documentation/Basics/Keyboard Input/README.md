# Keyboard Input

## KeyPressed and KeyReleased States

```cpp
// documentation/Basics/Keyboard Input/KeyPressedAndKeyReleased.cpp
#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

class Button : public RectRenderObject
{
  public:
    void Start() override { SetFillColor(255, 0, 0, 255); }

    void Update(double deltaTime) override
    {
        if (game->IsKeyPressed(SDLK_SPACE))
        {
            SetFillColor(255, 0, 0, 100);
        }
        else if (game->IsKeyPressed(SDLK_SPACE))
        {
            SetFillColor(255, 0, 0, 255);
        }
    }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<Button>());

    return game->Run();
}
```
