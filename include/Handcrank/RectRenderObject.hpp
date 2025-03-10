// Copyright (c) Scott Doxey. All Rights Reserved. Licensed under the MIT
// License. See LICENSE in the project root for license information.

#pragma once

#include <SDL.h>

#include "Handcrank.hpp"

namespace Handcrank
{

class RectRenderObject : public RenderObject
{
  protected:
    std::shared_ptr<SDL_Color> borderColor = std::make_shared<SDL_Color>();
    std::shared_ptr<SDL_Color> fillColor = std::make_shared<SDL_Color>();

    SDL_BlendMode blendMode = SDL_BLENDMODE_BLEND;

  public:
    explicit RectRenderObject() {}
    explicit RectRenderObject(const SDL_FRect _rect) { SetRect(_rect); }

    ~RectRenderObject() = default;

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
    }

    void SetBorderColor(const Uint8 r, const Uint8 g, const Uint8 b,
                        const Uint8 a)
    {
        borderColor->r = r;
        borderColor->g = g;
        borderColor->b = b;
        borderColor->a = a;
    }

    std::shared_ptr<SDL_Color> GetBorderColor() const { return borderColor; }

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
    }

    void SetFillColor(const Uint8 r, const Uint8 g, const Uint8 b,
                      const Uint8 a)
    {
        fillColor->r = r;
        fillColor->g = g;
        fillColor->b = b;
        fillColor->a = a;
    }

    std::shared_ptr<SDL_Color> GetFillColor() const { return fillColor; }

    /**
     * Render rect to the scene.
     *
     * @param renderer A structure representing rendering state.
     */
    void Render(std::shared_ptr<SDL_Renderer> renderer) override
    {
        SDL_SetRenderDrawBlendMode(renderer.get(), blendMode);

        auto transformedRect = GetTransformedRect();

        if (fillColor != nullptr)
        {
            SDL_SetRenderDrawColor(renderer.get(), fillColor->r, fillColor->g,
                                   fillColor->b, fillColor->a);

            SDL_RenderFillRectF(renderer.get(), &transformedRect);
        }

        if (borderColor != nullptr)
        {
            SDL_SetRenderDrawColor(renderer.get(), borderColor->r,
                                   borderColor->g, borderColor->b,
                                   borderColor->a);

            SDL_RenderDrawRectF(renderer.get(), &transformedRect);
        }

        RenderObject::Render(renderer);
    }
};

} // namespace Handcrank
