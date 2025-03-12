#pragma once

#include "../images/sdl_logo.h"

#include "Handcrank/Handcrank.hpp"

#include "../logo-screensaver/LogoScreenSaver.hpp"

using namespace Handcrank;

class Spawner : public RenderObject
{
  private:
    std::shared_ptr<SDL_Texture> texture;

  public:
    void Start() override
    {
        texture = SDL_LoadTextureRW(game->GetRenderer(), images_sdl_logo_png,
                                    images_sdl_logo_png_len);
    }
    void Update(const double deltaTime) override
    {
        if (!game->HasFocus())
        {
            return;
        }

        if (game->mousePressedState[SDL_BUTTON_LEFT])
        {
            auto logoScreenSaver = std::make_shared<LogoScreenSaver>();

            logoScreenSaver->SetTexture(texture);

            logoScreenSaver->SetRect(game->mousePosition->x,
                                     game->mousePosition->y);

            AddChildObject(logoScreenSaver);
        }
    }
};
