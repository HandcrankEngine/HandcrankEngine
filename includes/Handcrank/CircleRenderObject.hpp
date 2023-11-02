// Copyright (c) Scott Doxey. All Rights Reserved. Licensed under the MIT
// License. See LICENSE in the project root for license information.

#pragma once

#include <SDL.h>

#include "Handcrank.hpp"

namespace Handcrank
{

class CircleRenderObject : public RenderObject
{
  private:
    SDL_Color *borderColor;

    float radius;

    float circlePointsLength;

    std::vector<SDL_FPoint> circlePoints;

  public:
    explicit CircleRenderObject() {}
    explicit CircleRenderObject(SDL_FRect *rect) : RenderObject(rect) {}

    ~CircleRenderObject() = default;

    /**
     * Set rect border color.
     * @param color Color value to set.
     */
    void SetBorderColor(const SDL_Color borderColor)
    {
        if (this->borderColor == nullptr)
        {
            this->borderColor = new SDL_Color();
        }

        this->borderColor->r = borderColor.r;
        this->borderColor->g = borderColor.g;
        this->borderColor->b = borderColor.b;
        this->borderColor->a = borderColor.a;
    }

    void SetBorderColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
    {
        if (borderColor == nullptr)
        {
            borderColor = new SDL_Color();
        }

        borderColor->r = r;
        borderColor->g = g;
        borderColor->b = b;
        borderColor->a = a;
    }

    SDL_Color *GetBorderColor() const
    {
        if (borderColor == nullptr)
        {
            return nullptr;
        }

        return borderColor;
    }

    void SetRadius(const float radius)
    {
        circlePointsLength = radius;

        circlePoints.resize(circlePointsLength + 1);

        for (int i = 0; i < circlePointsLength; i += 1)
        {
            const double theta = 2.0 * M_PI * i / circlePointsLength;

            circlePoints[i] = {rect->x + radius * static_cast<float>(std::cos(theta)),
                               rect->y + radius * static_cast<float>(std::sin(theta))};
        }

        circlePoints[circlePointsLength] = circlePoints[0];

        this->radius = radius;
    }

    /**
     * Render rect to the scene.
     */
    void Render(SDL_Renderer *renderer) override
    {
        if (circlePointsLength > 0 && borderColor != nullptr)
        {
            SDL_SetRenderDrawColor(renderer, borderColor->r, borderColor->g,
                                   borderColor->b, borderColor->a);

            SDL_RenderDrawLinesF(renderer, &circlePoints[0],
                                 circlePointsLength + 1);
        }

        RenderObject::Render(renderer);
    }

    /**
     * Cleanup function to run after the RenderObject is unloaded.
     */
    void Clean() override {}
};

} // namespace Handcrank
