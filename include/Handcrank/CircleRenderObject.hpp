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
    std::shared_ptr<SDL_Color> borderColor = std::make_shared<SDL_Color>();

    bool borderColorSet = false;

    std::shared_ptr<SDL_Color> fillColor = std::make_shared<SDL_Color>();

    bool fillColorSet = false;

    float radius;

    float circlePointsLength;

    std::vector<SDL_FPoint> circlePoints{};

  public:
    explicit CircleRenderObject() {}
    explicit CircleRenderObject(const SDL_FRect _rect) : RenderObject(_rect) {}

    ~CircleRenderObject() = default;

    /**
     * Set rect border color.
     *
     * @param borderColor Color value to set.
     */
    void SetBorderColor(const SDL_Color borderColor)
    {
        this->borderColor->r = borderColor.r;
        this->borderColor->g = borderColor.g;
        this->borderColor->b = borderColor.b;
        this->borderColor->a = borderColor.a;

        borderColorSet = true;
    }

    void SetBorderColor(const Uint8 r, const Uint8 g, const Uint8 b,
                        const Uint8 a)
    {
        borderColor->r = r;
        borderColor->g = g;
        borderColor->b = b;
        borderColor->a = a;

        borderColorSet = true;
    }

    std::shared_ptr<SDL_Color> GetBorderColor() const
    {
        return borderColorSet ? borderColor : nullptr;
    }

    /**
     * Set rect fill color.
     *
     * @param fillColor Color value to set.
     */
    void SetFillColor(const SDL_Color fillColor)
    {
        this->fillColor->r = fillColor.r;
        this->fillColor->g = fillColor.g;
        this->fillColor->b = fillColor.b;
        this->fillColor->a = fillColor.a;

        fillColorSet = true;
    }

    void SetFillColor(const Uint8 r, const Uint8 g, const Uint8 b,
                      const Uint8 a)
    {
        fillColor->r = r;
        fillColor->g = g;
        fillColor->b = b;
        fillColor->a = a;

        fillColorSet = true;
    }

    std::shared_ptr<SDL_Color> GetFillColor() const
    {
        return fillColorSet ? fillColor : nullptr;
    }

    void SetRadius(const float _radius)
    {
        circlePointsLength = _radius;

        circlePoints.resize(circlePointsLength + 1);

        for (int i = 0; i < circlePointsLength; i += 1)
        {
            const double theta = 2.0 * M_PI * i / circlePointsLength;

            circlePoints[i] = {
                rect->x + _radius * static_cast<float>(std::cos(theta)),
                rect->y + _radius * static_cast<float>(std::sin(theta))};
        }

        circlePoints[circlePointsLength] = circlePoints[0];

        rect->w = _radius * 2;
        rect->h = _radius * 2;

        radius = _radius;
    }

    /**
     * Render rect to the scene.
     */
    void Render(std::shared_ptr<SDL_Renderer> renderer) override
    {
        if (circlePointsLength > 0 && borderColor != nullptr)
        {
            SDL_SetRenderDrawColor(renderer.get(), borderColor->r,
                                   borderColor->g, borderColor->b,
                                   borderColor->a);

            SDL_RenderDrawLinesF(renderer.get(), &circlePoints[0],
                                 circlePointsLength + 1);
        }
    }
};

} // namespace Handcrank
