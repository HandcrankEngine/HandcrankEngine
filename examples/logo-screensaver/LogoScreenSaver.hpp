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
            LoadTexture(game->GetRenderer(), images_sdl_logo_png,
                        images_sdl_logo_png_len);
        }

        if (rect.x == 0 && rect.y == 0)
        {
            SetPosition(RandomNumberRange(0, game->GetWidth()),
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

        const auto minX = transformedRect.w / 2;
        const auto minY = transformedRect.h / 2;

        const auto maxX = game->GetWidth() - (transformedRect.w / 2);
        const auto maxY = game->GetHeight() - (transformedRect.h / 2);

        float x = rect.x + (movementSpeed * xDirection * deltaTime);
        float y = rect.y + (movementSpeed * yDirection * deltaTime);

        if (x > maxX || x < minX)
        {
            xDirection = -xDirection;
        }

        if (y > maxY || y < minY)
        {
            yDirection = -yDirection;
        }

        x = std::clamp<float>(x, minX, maxX);
        y = std::clamp<float>(y, minY, maxY);

        SetPosition(x, y);
    }
};
