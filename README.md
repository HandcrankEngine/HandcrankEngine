> [!WARNING]
> This custom game engine is under early development and should not be used.

# Handcrank Engine

[![Test](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/test.workflow.yml/badge.svg)](https://github.com/HandcrankEngine/HandcrankEngine/actions/workflows/test.workflow.yml)

## Quickstart

```cpp
#include "Handcrank/Game.hpp"

auto game = new Handcrank::Game();

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    return game->Run();
}
```
