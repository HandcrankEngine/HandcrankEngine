#pragma once

#include <algorithm>

#include "../images/sdl_logo.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/ImageRenderObject.hpp"
#include "Handcrank/Utilities.hpp"

using namespace Handcrank;

class LogoScreenSaver : public ImageRenderObject
{
  protected:
    int xDirection = RandomBoolean() ? -1 : 1;
    int yDirection = RandomBoolean() ? -1 : 1;

    int movementSpeed = (rand() % 400) + 100;

  public:
    void Start() override
    {
        SetAnchor(RectAnchor::HCENTER | RectAnchor::VCENTER);

        if (texture == nullptr)
        {
            LoadTextureRW(game->GetRenderer(), images_sdl_logo_png,
                          images_sdl_logo_png_len);
        }

        if (rect->x == 0 && rect->y == 0)
        {
            SetRect(RandomNumberRange(0, game->GetWidth()),
                    RandomNumberRange(0, game->GetHeight()));
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

        const auto minX = transformedRect.w / 2;
        const auto minY = transformedRect.h / 2;

        const auto maxX = game->GetWidth() - (transformedRect.w / 2);
        const auto maxY = game->GetHeight() - (transformedRect.h / 2);

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
