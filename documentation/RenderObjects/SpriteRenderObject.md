# SpriteRenderObject

## Rendering Animated Sprite Sheets

```cpp
#pragma once

#include "../images/character-idle.h"

#include "HandcrankEngine/Handcrank.hpp"
#include "HandcrankEngine/SpriteRenderObject.hpp"

using namespace Handcrank;

class Character : public SpriteRenderObject
{
  public:
    void Start() override
    {
        LoadTexture(game->GetRenderer(), images_character_idle_png,
                      images_character_idle_png_len);

        SetFrameSpeed(0.1);

        CalculateFrames(300, 60, 8, 1, Vector2(0, 0), Vector2(0, 0));

        Play();
    }
};
```
