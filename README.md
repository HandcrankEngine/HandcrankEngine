> [!WARNING]
> This custom game engine is under early development and should not be used.

# Handcrank Engine

[![Build](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/build.workflow.yml/badge.svg)](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/build.workflow.yml)
[![Lint](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/lint.workflow.yml/badge.svg)](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/lint.workflow.yml)
[![Tests](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/test.workflow.yml/badge.svg)](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/test.workflow.yml)

## Demo

https://github.com/user-attachments/assets/bdf51feb-13ae-4da3-8a40-8987b28a0842

## Quick Start

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

## Dependencies

```bash
brew install cmake
brew install clang-format
brew install SDL2
brew install SDL2_image
brew install SDL2_ttf
```

## Documentation

1. [Basics](documentation/Basics)

   1. [Keyboard Input](documentation/Basics/Keyboard%20Input.md)
   1. [Mouse Input](documentation/Basics/Mouse%20Input.md)
   1. [Update Loop](documentation/Basics/Update%20Loop.md)

1. [Building](documentation/Building)

   1. [macOS](documentation/Building/macOS.md)
   1. [Windows](documentation/Building/Windows.md)

1. [Examples](documentation/Examples)

   1. [FPS](documentation/Examples/FPS.md)

1. [RenderObjects](documentation/RenderObjects)

   1. [Custom RenderObject](documentation/RenderObjects/Custom%20RenderObject.md)
   1. [ImageRenderObject](documentation/RenderObjects/ImageRenderObject.md)
   1. [RectRenderObject](documentation/RenderObjects/RectRenderObject.md)
   1. [SpriteRenderObject](documentation/RenderObjects/SpriteRenderObject.md)
   1. [TextRenderObject](documentation/RenderObjects/TextRenderObject.md)

## Build

### Native

Using CMake

```bash
cmake .
make
```

or using g++

```bash
./bin/build.sh
```

## Documentation

```bash
$ brew install doxygen
```

```bash
$ doxygen
```

## Format

```bash
clang-format -i src/*.cpp include/**/*.hpp tests/**/*.cpp
```

## Tidy

```bash
clang-tidy include/**/*.hpp
```

## Editor Setup

### VS Code

Make sure the paths are correct in `.vscode/c_cpp_properties.json`.

### zed

Make sure the paths are correct in `.clangd`.

### Sublime Text

Via Package Control, install `LSP` and `LSP-clangd`.
