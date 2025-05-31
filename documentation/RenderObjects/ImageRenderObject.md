# ImageRenderObject

## Loading and Rendering Images

```cpp
#include "../images/sdl_logo.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/ImageRenderObject.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

class SDL_Logo : public ImageRenderObject
{
  public:
    void Start() override
    {
        LoadTexture(game->GetRenderer(), images_sdl_logo_png,
                      images_sdl_logo_png_len);
    }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<SDL_Logo>()));

    return game->Run();
}
```
