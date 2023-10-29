> [!WARNING]
> This custom game engine is under early development and should not be used.

# Handcrank Engine

[![Build](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/build.workflow.yml/badge.svg)](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/build.workflow.yml)
[![Lint](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/lint.workflow.yml/badge.svg)](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/lint.workflow.yml)
[![Tests](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/test.workflow.yml/badge.svg)](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/test.workflow.yml)

## Quick Start

```cpp
#include "Handcrank/Handcrank.hpp"

using namespace Handcrank;

auto game = new Game();

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    return game->Run();
}
```

## Examples

1. [Adding Native Objects](#adding-native-objects)
1. [Creating Custom Objects](#creating-custom-objects)
1. [Update and FixedUpdate Events](#update-and-fixedupdate-events)
1. [KeyPressed and KeyReleased States](#keypressed-and-keyreleased-states)
1. [Mouse Position](#mouse-position)
1. [MouseOver and MouseOut Events](#mouseover-and-mouseout-events)
1. [MouseDown and MouseUp Events](#mousedown-and-mouseup-events)
1. [Loading Fonts and Rendering Text](#loading-fonts-and-rendering-text)
1. [Display FPS](#display-fps)

### Adding Native Objects

```cpp
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = new Game();

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    auto square = std::make_unique<RectRenderObject>();

    square->SetFillColor({255, 0, 0, 255});

    game->AddChildObject(std::move(square));

    return game->Run();
}
```

### Creating Custom Objects

```cpp
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = new Game();

class RedSquare : public RectRenderObject
{

  public:
    void Start() override { SetFillColor({255, 0, 0, 255}); }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<RedSquare>()));

    return game->Run();
}
```

### Update and FixedUpdate Events

```cpp
#include <iostream>

#include "Handcrank/Handcrank.hpp"

using namespace Handcrank;

auto game = new Game();

class LoopDebugger : public RenderObject
{

  public:
    void Update(double deltaTime) override
    {
        std::cout << "Update" << std::endl;
    }
    void FixedUpdate(double deltaTime) override
    {
        std::cout << "Fixed Update" << std::endl;
    }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<LoopDebugger>()));

    return game->Run();
}
```

### KeyPressed and KeyReleased States

```cpp
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = new Game();

class Button : public RectRenderObject
{

  public:
    void Start() override { SetFillColor(255, 0, 0, 255); }
    void Update(double deltaTime) override
    {
        if (game->keyPressedState[SDLK_SPACE])
        {
            SetFillColor(255, 0, 0, 100);
        }
        else if (game->keyReleasedState[SDLK_SPACE])
        {
            SetFillColor(255, 0, 0, 255);
        }
    }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<Button>()));

    return game->Run();
}
```

### Mouse Position

```cpp
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = new Game();

class Cursor : public RectRenderObject
{

  public:
    void Start() override { SetFillColor(255, 0, 0, 255); }
    void Update(double deltaTime) override
    {
        SetRect(game->mousePosition->x - 50, game->mousePosition->y - 50);
    }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<Cursor>()));

    return game->Run();
}
```

### MouseOver and MouseOut Events

```cpp
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = new Game();

class Button : public RectRenderObject
{

  public:
    void Start() override { SetFillColor(255, 0, 0, 255); }
    void OnMouseOver() override { SetFillColor(255, 0, 0, 100); }
    void OnMouseOut() override { SetFillColor(255, 0, 0, 255); }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<Button>()));

    return game->Run();
}
```

### MouseDown and MouseUp Events

```cpp
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = new Game();

class Button : public RectRenderObject
{

  public:
    void Start() override { SetFillColor(255, 0, 0, 255); }
    void OnMouseDown() override { SetFillColor(255, 0, 0, 100); }
    void OnMouseUp() override { SetFillColor(255, 0, 0, 255); }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<Button>()));

    return game->Run();
}
```

### Loading Fonts and Rendering Text

> [!NOTE]
> Fonts can be loaded by using `SDL_LoadFont` but it will only work for local builds where the font is always in the same path. Use `SDL_LoadFontRW` on header files generated by using `xxd -i "Font.ttf" "Font.h` or the included `bin/compile-static-assets.h` bash script to make sure they work even after the build file has been moved.

```cpp
#include "../fonts/Roboto/Roboto-Regular.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/TextRenderObject.hpp"

#include "Handcrank/sdl/SDL_TTF_Utilities.hpp"

using namespace Handcrank;

auto game = new Game();

auto font = SDL_LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                           fonts_Roboto_Roboto_Regular_ttf_len, 30);

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    auto label = std::make_unique<TextRenderObject>();

    label->SetFont(font);

    label->SetText("Hello, World");

    game->AddChildObject(std::move(label));

    return game->Run();
}
```

### Display FPS

```cpp
#include "../fonts/Roboto/Roboto-Regular.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/TextRenderObject.hpp"

#include "Handcrank/sdl/SDL_TTF_Utilities.hpp"

using namespace Handcrank;

auto game = new Game();

auto font = SDL_LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                           fonts_Roboto_Roboto_Regular_ttf_len, 30);

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    auto framerateLabel = std::make_unique<TextRenderObject>();

    framerateLabel->SetFont(font);

    framerateLabel->SetUpdate(
        [](RenderObject *ref, double deltaTime)
        {
            auto textRenderObject = dynamic_cast<TextRenderObject *>(ref);

            textRenderObject->SetText(std::to_string(game->GetFPS()));
        });

    game->AddChildObject(std::move(framerateLabel));

    return game->Run();
}
```
