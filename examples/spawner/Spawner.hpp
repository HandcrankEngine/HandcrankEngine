#pragma once

#include "../fonts/Roboto/Roboto-Regular.h"
#include "../images/sdl_logo.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"
#include "Handcrank/TextRenderObject.hpp"

#include "../logo-screensaver/LogoScreenSaver.hpp"

using namespace Handcrank;

class Spawner : public RenderObject
{
  private:
    std::shared_ptr<TextRenderObject> label =
        std::make_shared<TextRenderObject>();
    std::shared_ptr<RectRenderObject> background =
        std::make_shared<RectRenderObject>();

  public:
    void Start() override
    {
        AddChildObject(background);

        background->SetRect({(float)game->GetWidth() - 200,
                             (float)game->GetHeight() - 125, 200, 70});
        background->SetFillColor({255, 255, 255, 255});

        background->z = 1;

        label->SetRect({10, 10});
        label->LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                          fonts_Roboto_Roboto_Regular_ttf_len, 40);

        label->SetColor({0, 0, 0, 255});

        background->AddChildObject(label);
    }
    void Update(const double deltaTime) override
    {
        if (!game->HasFocus())
        {
            return;
        }

        if (game->mouseState[SDL_BUTTON_LEFT])
        {
            auto logoScreenSaver = std::make_shared<LogoScreenSaver>();

            logoScreenSaver->LoadTexture(game->GetRenderer(),
                                         images_sdl_logo_png,
                                         images_sdl_logo_png_len);

            logoScreenSaver->SetPosition(game->mousePosition->x,
                                         game->mousePosition->y);

            AddChildObject(logoScreenSaver);
        }

        auto spawnedLogos = GetChildrenByType<LogoScreenSaver>();

        if (game->keyPressedState[SDLK_c])
        {
            for (const auto &child : spawnedLogos)
            {
                child->Destroy();
            }
        }

        auto logoCount = spawnedLogos.size();

        label->SetText(std::to_string(logoCount));
    }
};
