# TextRenderObject

## Loading Fonts and Rendering Text

```cpp
#include "../fonts/Roboto/Roboto-Regular.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/TextRenderObject.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    auto label = std::make_unique<TextRenderObject>();

    label->LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                      fonts_Roboto_Roboto_Regular_ttf_len, 30);

    label->SetText("Hello, World");

    game->AddChildObject(std::move(label));

    return game->Run();
}
```
