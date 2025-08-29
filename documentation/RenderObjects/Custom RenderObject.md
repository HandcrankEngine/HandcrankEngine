# Custom RenderObject

## Creating Custom Objects

```cpp
#include "HandcrankEngine/Handcrank.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

class RedSquare : public RectRenderObject
{
public:
    void Start() override { SetFillColor(255, 0, 0, 255); }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<RedSquare>()));

    return game->Run();
}
```
