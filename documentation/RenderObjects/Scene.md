# Scene

## Creating a Scene

```cpp
#pragma once

#include "../images/sdl_logo.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/ImageRenderObject.hpp"
#include "HandcrankEngine/Scene.hpp"

using namespace HandcrankEngine;

class LogoScene : public Scene
{
  private:
    std::shared_ptr<ImageRenderObject> logo;

  public:
    void Start() override
    {
        logo = std::make_shared<ImageRenderObject>();

        logo->LoadTexture(game->GetRenderer(), images_sdl_logo_png,
                          images_sdl_logo_png_len);

        logo->SetScale(scale);
        logo->SetPosition(game->GetWidth() / 2, game->GetHeight() / 2);
        logo->SetAnchor(RectAnchor::HCENTER | RectAnchor::VCENTER);

        AddChildObject(logo);
    }
};
```

## Creating a SceneManager

```cpp
#define HANDCRANK_ENGINE_DEBUG 1

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/SceneManager.hpp"

#include "scenes/LogoScene.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

auto main() -> int
{
    auto sceneManager = std::make_shared<SceneManager>();

    game->AddChildObject(sceneManager);

    sceneManager->AddScene(std::make_shared<LogoScene>());

    sceneManager->SetCurrentScene<LogosScene>();

    return game->Run();
}
```

## Switching to Another Scene

```cpp
#pragma once

#include "../images/logo.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/ImageRenderObject.hpp"
#include "HandcrankEngine/Scene.hpp"

#include "scenes/TitleScene.hpp"

using namespace HandcrankEngine;

class LogosScene : public Scene
{
  private:
    std::shared_ptr<ImageRenderObject> logo;

  public:
    void Start() override
    {
        logo = std::make_shared<ImageRenderObject>();

        logo->LoadTexture(game->GetRenderer(), images_sdl_logo_png,
                          images_sdl_logo_png_len);

        logo->SetScale(scale);
        logo->SetPosition(game->GetWidth() / 2, game->GetHeight() / 2);
        logo->SetAnchor(RectAnchor::HCENTER | RectAnchor::VCENTER);

        AddChildObject(logo);
    }

    void Update(const double deltaTime) override
    {
        if (game->IsAnyKeyPressed())
        {
            SwitchToScene<TitleScene>();
        }
    }
};
```
