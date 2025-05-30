> [!WARNING]
> This custom game engine is under early development and should not be used.

# Handcrank Engine

[![Made With SDL2](https://img.shields.io/badge/Made_With-SDL2-blue)](https://www.libsdl.org/)
[![Build](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/build.workflow.yml/badge.svg)](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/build.workflow.yml)
[![Lint](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/lint.workflow.yml/badge.svg)](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/lint.workflow.yml)
[![Tests](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/test.workflow.yml/badge.svg)](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/test.workflow.yml)

## Demo

https://github.com/user-attachments/assets/bdf51feb-13ae-4da3-8a40-8987b28a0842

## Social

- Star [this repo on GitHub](https://github.com/HandcrankEngine/HandcrankEngine) for updates
- Follow me on [Bluesky](https://bsky.app/profile/scottdoxey.com)
- Join the [Discord](https://discord.gg/nNtFsfd)
- Follow me on [GitHub](https://github.com/neogeek/)

## Platforms

| Platform                                  | SDL Version | Tested | Stable |
| ----------------------------------------- | :---------: | :----: | :----: |
| [Windows](documentation/Build/Windows.md) |   2.32.6    |   ✅   |   ❌   |
| [macOS](documentation/Build/macOS.md)     |   2.32.6    |   ✅   |   ❌   |
| [Web](documentation/Build/Web.md)         |   2.32.6    |   ✅   |   ❌   |

## Quick Start Guide

```cpp
#include "Handcrank/Handcrank.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    return game->Run();
}
```

## Documentation

1. [Basics](/documentation/Basics)

   1. [Animations](/documentation/Basics/Animations.md)
   1. [Keyboard Input](/documentation/Basics/Keyboard%20Input.md)
   1. [Mouse Input](/documentation/Basics/Mouse%20Input.md)
   1. [Update Loop](/documentation/Basics/Update%20Loop.md)

1. [Building](/documentation/Building)

   1. [Windows](/documentation/Building/Windows.md)
   1. [macOS](/documentation/Building/macOS.md)
   1. [Web](/documentation/Building/Web.md)

1. [Examples](/documentation/Examples)

   1. [FPS](/documentation/Examples/FPS.md)

1. [RenderObjects](/documentation/RenderObjects)

   1. [Custom RenderObject](/documentation/RenderObjects/Custom%20RenderObject.md)
   1. [ImageRenderObject](/documentation/RenderObjects/ImageRenderObject.md)
   1. [RectRenderObject](/documentation/RenderObjects/RectRenderObject.md)
   1. [SpriteRenderObject](/documentation/RenderObjects/SpriteRenderObject.md)
   1. [TextRenderObject](/documentation/RenderObjects/TextRenderObject.md)

## Getting Started

### Draw Rectangle

```cpp
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    auto rect = std::make_shared<RectRenderObject>();

    rect->SetRect(0, 0, 250, 250);
    rect->SetFillColor(255, 0, 0, 255);

    game->AddChildObject(rect);

    return game->Run();
}
```

### Draw Image

```cpp
#include "../images/sdl_logo.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/ImageRenderObject.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    auto image = std::make_shared<ImageRenderObject>();

    image->LoadTextureRW(game->GetRenderer(), images_sdl_logo_png,
                         images_sdl_logo_png_len);

    game->AddChildObject(image);

    return game->Run();
}
```

## Build

### CMake (Recommended)

> Note: Builds on Windows require [Microsoft Visual C++ Redistributable](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170) to run.

#### Debug Build

```bash
mkdir build/
cd build/
cmake ..
cmake --build .
```

#### Release Build

> Note: To generate DMG files on macOS, first build with cmake, then run `cpack`.

```bash
mkdir build/
cd build/
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

### g++

```bash
./bin/build.sh
```

## Demos

| Name      | Link                                           | Source Included? |
| --------- | ---------------------------------------------- | :--------------: |
| Template  | <https://github.com/HandcrankEngine/template>  |        ✅        |
| Pong Demo | <https://github.com/HandcrankEngine/pong-demo> |        ✅        |

## Contributing

Be sure to review the [Contributing Guidelines](./CONTRIBUTING.md) before logging an issue or making a pull request.

## Community Roadmap

The goal of this project is to keep the features it offers to a minimum, allowing you, the developer, to forge your own path. If you have feature requests or bugs, please create an issue and tag them with the appropriate tag. If an issue already exists, vote for it with 👍.

- [Feature Requests](https://github.com/HandcrankEngine/HandcrankEngine/labels/enhancement)
- [Bugs](https://github.com/HandcrankEngine/HandcrankEngine/labels/bug)

## License

[The MIT License (MIT)](./LICENSE)
