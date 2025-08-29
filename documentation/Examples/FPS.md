# FPS

```cpp
#include "../fonts/Roboto/Roboto-Regular.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/TextRenderObject.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

class FPS : public TextRenderObject
{
  public:
    void Start() override
    {
        LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                   fonts_Roboto_Roboto_Regular_ttf_len, 30);
    }
    void Update(const double deltaTime) override
    {
        SetText(std::to_string(game->GetFPS()));
    }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<FPS>()));

    return game->Run();
}
```
