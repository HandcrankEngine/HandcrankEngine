# Mouse Input

## Mouse Position

```cpp
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

class Cursor : public RectRenderObject
{
  public:
    void Start() override { SetFillColor(255, 0, 0, 255); }
    void Update(const double deltaTime) override
    {
        SetRect(game->mousePosition->x - 50, game->mousePosition->y - 50);
    }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<Cursor>()));

    return game->Run();
}
```

## MouseOver and MouseOut Events

```cpp
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

class Button : public RectRenderObject
{
  public:
    void Start() override { SetFillColor(255, 0, 0, 255); }
    void OnMouseOver() override { SetFillColor(255, 0, 0, 100); }
    void OnMouseOut() override { SetFillColor(255, 0, 0, 255); }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<Button>()));

    return game->Run();
}
```

## MouseDown and MouseUp Events

```cpp
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

class Button : public RectRenderObject
{
  public:
    void Start() override { SetFillColor(255, 0, 0, 255); }
    void OnMouseDown() override { SetFillColor(255, 0, 0, 100); }
    void OnMouseUp() override { SetFillColor(255, 0, 0, 255); }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::move(std::make_unique<Button>()));

    return game->Run();
}
```
