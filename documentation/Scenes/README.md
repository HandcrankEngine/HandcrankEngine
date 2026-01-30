# Scene

## Creating a Scene

```cpp
// documentation/Scenes/CreatingAScene.cpp
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

auto main() -> int
{
    auto game = std::make_unique<Game>();

    return game->Run();
}
```

## Managing Scenes with SceneManager

```cpp
// documentation/Scenes/ManagingScenesWithSceneManager.cpp
#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/SceneManager.hpp"

using namespace HandcrankEngine;

class LogosScene : public Scene
{
};

auto main() -> int
{
    auto game = std::make_unique<Game>();

    auto sceneManager = std::make_shared<SceneManager>();

    game->AddChildObject(sceneManager);

    sceneManager->AddScene(std::make_shared<LogosScene>());

    sceneManager->SetCurrentScene<LogosScene>();

    return game->Run();
}
```

## Switching Scenes

```cpp
// documentation/Scenes/SwitchingScenes.cpp
#include "../images/sdl_logo.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/ImageRenderObject.hpp"
#include "HandcrankEngine/Scene.hpp"

using namespace HandcrankEngine;

class TitleScene : public Scene
{
};

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

    void Update(double deltaTime) override
    {
        if (game->IsAnyKeyPressed())
        {
            SwitchToScene<TitleScene>();
        }
    }
};

auto main() -> int
{
    auto game = std::make_unique<Game>();

    return game->Run();
}
```
