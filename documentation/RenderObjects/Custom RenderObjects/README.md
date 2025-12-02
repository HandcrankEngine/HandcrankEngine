# Custom RenderObject

## Creating Custom Objects

```cpp
// documentation/RenderObjects/Custom RenderObjects/CustomRenderObject.cpp
#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

class RedSquare : public RectRenderObject
{
public:
    void Start() override { SetFillColor(255, 0, 0, 255); }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<RedSquare>());

    return game->Run();
}
```
