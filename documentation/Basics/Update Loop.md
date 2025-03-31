# Update Loop

## Update and FixedUpdate Events

```cpp
#include <iostream>

#include "Handcrank/Handcrank.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

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

## Inline Update and FixedUpdate Events

```cpp
#include <iostream>

#include "Handcrank/Handcrank.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

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
