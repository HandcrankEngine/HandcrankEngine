#pragma once

#include <algorithm>

#include "../images/sdl_logo.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/ImageRenderObject.hpp"

using namespace Handcrank;

int randomNumberRange(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int randomBoolean() { return rand() > (RAND_MAX / 2); }

class LogoScreenSaver : public ImageRenderObject
{
  protected:
    int xDirection = randomBoolean() ? -1 : 1;
    int yDirection = randomBoolean() % 1 ? -1 : 1;

    int movementSpeed = rand() % 400 + 100;

  public:
    void Start() override
    {
        LoadTextureRW(game->GetRenderer(), images_sdl_logo_png,
                      images_sdl_logo_png_len);

        if (rect->x == 0 && rect->y == 0)
        {
            SetRect(randomNumberRange(0, game->GetWidth() - 200),
                    randomNumberRange(0, game->GetWidth() - 200));
        }
    }

    void Update(const double deltaTime) override
    {
        if (!game->HasFocus())
        {
            return;
        }

        const auto transformedRect = GetTransformedRect();

        const auto rect = GetRect();

        const auto minX = 0;
        const auto minY = 0;

        const auto maxX = game->GetWidth() - transformedRect.w;
        const auto maxY = game->GetHeight() - transformedRect.h;

        rect->x += movementSpeed * xDirection * deltaTime;
        rect->y += movementSpeed * yDirection * deltaTime;

        if (rect->x > maxX || rect->x < minX)
        {
            xDirection = -xDirection;
        }

        if (rect->y > maxY || rect->y < minY)
        {
            yDirection = -yDirection;
        }

        rect->x = std::clamp<float>(rect->x, minX, maxX);
        rect->y = std::clamp<float>(rect->y, minY, maxY);
    }
};
