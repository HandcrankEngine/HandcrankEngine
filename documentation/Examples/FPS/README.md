# FPS

```cpp
// documentation/Examples/FPS/FPS.cpp
#include "../fonts/Roboto/Roboto-Regular.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/TextRenderObject.hpp"

using namespace HandcrankEngine;

class FPS : public TextRenderObject
{
  public:
    void Start() override
    {
        LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                   fonts_Roboto_Roboto_Regular_ttf_len, 30);
    }
    void Update(double deltaTime) override
    {
        SetText(std::to_string(game->GetFPS()));
    }
};

auto main(int argc, char *argv[]) -> int
{
    auto game = std::make_unique<Game>();

    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<FPS>());

    return game->Run();
}
```
