# SpriteRenderObject

## Rendering Animated Sprite Sheet

```cpp
// documentation/RenderObjects/SpriteRenderObject/RenderingAnimatedSpriteSheet.cpp
#include "../images/alienGreen.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/SpriteRenderObject.hpp"

using namespace HandcrankEngine;

class Character : public SpriteRenderObject
{
  public:
    void Start() override
    {
        LoadTexture(game->GetRenderer(), images_alienGreen_png,
                      images_alienGreen_png_len);

        SetFrameSpeed(0.1);

        CalculateFrames(300, 60, 8, 1, Vector2(0, 0), Vector2(0, 0));

        Play();
    }
};

auto game = std::make_unique<Game>();

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<Character>());

    return game->Run();
}
```
