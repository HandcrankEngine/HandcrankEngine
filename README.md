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

## Adding Native Objects

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

## Creating Custom Objects

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
