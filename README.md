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

1. [Rendering Rectangle Object](#rendering-rectangle-object)
1. [Creating Custom Objects](#creating-custom-objects)
1. [Update and FixedUpdate Events](#update-and-fixedupdate-events)
1. [Inline Update and FixedUpdate Events](#inline-update-and-fixedupdate-events)
1. [KeyPressed and KeyReleased States](#keypressed-and-keyreleased-states)
1. [Mouse Position](#mouse-position)
1. [MouseOver and MouseOut Events](#mouseover-and-mouseout-events)
1. [MouseDown and MouseUp Events](#mousedown-and-mouseup-events)
1. [Loading Fonts and Rendering Text](#loading-fonts-and-rendering-text)
1. [Display FPS](#display-fps)
1. [Loading and Rendering Images](#loading-and-rendering-images)

### Rendering Rectangle Object

```cpp
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = new Game();

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    auto square = std::make_unique<RectRenderObject>();

    square->SetFillColor(255, 0, 0, 255);

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
    void Start() override { SetFillColor(255, 0, 0, 255); }
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
    void Update(const double deltaTime) override
    {
        std::cout << "Update" << std::endl;
    }
    void FixedUpdate(const double fixedDeltaTime) override
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

### Inline Update and FixedUpdate Events

```cpp
#include <iostream>

#include "Handcrank/Handcrank.hpp"

using namespace Handcrank;

auto game = new Game();

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    auto loopDebugger = std::make_unique<RenderObject>();

    loopDebugger->SetUpdate([](RenderObject *ref, const double deltaTime)
                            { std::cout << "Update" << std::endl; });

    loopDebugger->SetFixedUpdate([](RenderObject *ref, const double fixedDeltaTime)
                                 { std::cout << "Fixed Update" << std::endl; });

    game->AddChildObject(std::move(loopDebugger));

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
    void Update(const double deltaTime) override
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
    void Update(const double deltaTime) override
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
> Fonts can be loaded by using `SDL_LoadFont` but it will only work for local builds where the font is always in the same path. Use `SDL_LoadFontRW` on header files generated by using `xxd -i "Font.ttf" "Font.h"` or the included `bin/compile-static-assets.h` bash script to make sure they work even after the build file has been moved.

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

auto robotoFont = SDL_LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                                 fonts_Roboto_Roboto_Regular_ttf_len, 30);

class FPS : public TextRenderObject
{
  public:
    void Start() override { SetFont(robotoFont); }
    void Update(const double deltaTime) override
    {
        SetText(std::to_string(game->GetFPS()));
    }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<FPS>()));

    return game->Run();
}
```

### Loading and Rendering Images

> [!NOTE]
> Similar to fonts, images can be loaded by using `SDL_LoadTexture` but it will only work for local builds where the image is always in the same path. Use `SDL_LoadTextureRW` on header files generated by using `xxd -i "Image.png" "Image.h"` or the included `bin/compile-static-assets.h` bash script to make sure they work even after the build file has been moved.

```cpp
#include <algorithm>

#include "../images/sdl_logo.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/ImageRenderObject.hpp"

using namespace Handcrank;

auto game = new Game();

class SDL_Logo : public ImageRenderObject
{
  public:
    void Start() override
    {
        LoadTextureRW(game->GetRenderer(), images_sdl_logo_png,
                      images_sdl_logo_png_len);
    }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<SDL_Logo>()));

    return game->Run();
}
```
