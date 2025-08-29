# RectRenderObject

## Rendering Rectangle Object

```cpp
#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    auto square = std::make_unique<RectRenderObject>();

    square->SetFillColor(255, 0, 0, 255);

    game->AddChildObject(std::move(square));

    return game->Run();
}
```
