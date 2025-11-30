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

auto game = std::make_unique<Game>();

auto main() -> int
{
    return game->Run();
}

