# Getting Started

## Quick Start

```cpp
// documentation/Getting Started/QuickStart.cpp
#include "HandcrankEngine/HandcrankEngine.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    return game->Run();
}
```

## Draw Rectangle

```cpp
// documentation/Getting Started/DrawRectangle.cpp
#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    auto rect = std::make_shared<RectRenderObject>();

    rect->SetRect(0, 0, 250, 250);
    rect->SetFillColor(255, 0, 0, 255);

    game->AddChildObject(rect);

    return game->Run();
}
```

## Draw Image

```cpp
// documentation/Getting Started/DrawImage.cpp
#include "../images/sdl_logo.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/ImageRenderObject.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    auto image = std::make_shared<ImageRenderObject>();

    image->LoadTexture(game->GetRenderer(), images_sdl_logo_png,
                         images_sdl_logo_png_len);

    game->AddChildObject(image);

    return game->Run();
}
```
