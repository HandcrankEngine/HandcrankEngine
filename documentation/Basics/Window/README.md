# Window

```cpp
// documentation/Basics/Window/Window.cpp
#include "HandcrankEngine/HandcrankEngine.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    return game->Run();
}
```
