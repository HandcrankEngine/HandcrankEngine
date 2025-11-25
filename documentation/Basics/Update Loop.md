# Update Loop

## Update and FixedUpdate Events

```cpp
#include <iostream>

#include "HandcrankEngine/HandcrankEngine.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

class LoopDebugger : public RenderObject
{
  public:
    void Update(double deltaTime) override
    {
        std::cout << "Update " << std::to_string(deltaTime) << std::endl;
    }

    void FixedUpdate(double fixedDeltaTime) override
    {
        std::cout << "Fixed Update " << std::to_string(fixedDeltaTime)
                  << std::endl;
    }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<LoopDebugger>()));

    return game->Run();
}
```
