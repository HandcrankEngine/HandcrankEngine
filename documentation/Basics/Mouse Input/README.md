# Mouse Input

## Mouse Position

```cpp
// documentation/Basics/Mouse Input/MousePosition.cpp
#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

class Cursor : public RectRenderObject
{
  public:
    void Start() override { SetFillColor(255, 0, 0, 255); }

    void Update(double deltaTime) override
    {
        SetPosition(game->GetMousePosition().x - 50, game->GetMousePosition().y - 50);
    }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<Cursor>());

    return game->Run();
}
```

## MouseOver and MouseOut Events

```cpp
// documentation/Basics/Mouse Input/MouseOverAndMouseOutEvents.cpp
#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

class Button : public RectRenderObject
{
  public:
    void Start() override { SetFillColor(255, 0, 0, 255); }
    void OnMouseOver() override { SetFillColor(255, 0, 0, 100); }
    void OnMouseOut() override { SetFillColor(255, 0, 0, 255); }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<Button>());

    return game->Run();
}
```

## MouseDown and MouseUp Events

```cpp
// documentation/Basics/Mouse Input/MouseDownAndMouseUpEvents.cpp
#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

class Button : public RectRenderObject
{
  public:
    void Start() override { SetFillColor(255, 0, 0, 255); }
    void OnMouseDown() override { SetFillColor(255, 0, 0, 100); }
    void OnMouseUp() override { SetFillColor(255, 0, 0, 255); }
};

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<Button>());

    return game->Run();
}
```
