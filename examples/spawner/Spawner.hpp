#pragma once

#include "Handcrank/Handcrank.hpp"

#include "../logo-screensaver/LogoScreenSaver.hpp"

using namespace Handcrank;

class Spawner : public RenderObject
{
  public:
    void Update(const double deltaTime) override
    {
        if (!game->HasFocus())
        {
            return;
        }

        if (game->mousePressedState[SDL_BUTTON_LEFT])
        {
            auto logoScreenSaver = std::make_shared<LogoScreenSaver>();

            logoScreenSaver->SetRect(game->mousePosition->x,
                                     game->mousePosition->y);

            AddChildObject(logoScreenSaver);
        }
    }
};
