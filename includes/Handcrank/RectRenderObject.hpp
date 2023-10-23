// Copyright (c) Scott Doxey. All Rights Reserved. Licensed under the MIT
// License. See LICENSE in the project root for license information.

#pragma once

#include <SDL.h>

#include "Handcrank.hpp"

namespace Handcrank
{

class RectRenderObject : public RenderObject
{
  private:
    SDL_Color *borderColor;
    SDL_Color *fillColor;

  public:
    explicit RectRenderObject() : RenderObject() {}
    explicit RectRenderObject(SDL_FRect *_rect) : RenderObject(_rect) {}

    ~RectRenderObject() = default;

    /**
     * Set rect border color.
     * @param color Color value to set.
     */
    void SetBorderColor(SDL_Color _borderColor)
    {
        if (borderColor == nullptr)
        {
            borderColor = new SDL_Color();
        }

        borderColor->r = _borderColor.r;
        borderColor->g = _borderColor.g;
        borderColor->b = _borderColor.b;
        borderColor->a = _borderColor.a;
    }

    /**
     * Set rect fill color.
     * @param color Color value to set.
     */
    void SetFillColor(SDL_Color _fillColor)
    {
        if (fillColor == nullptr)
        {
            fillColor = new SDL_Color();
        }

        fillColor->r = _fillColor.r;
        fillColor->g = _fillColor.g;
        fillColor->b = _fillColor.b;
        fillColor->a = _fillColor.a;
    }

    /**
     * Render rect to the scene.
     */
    void Render(SDL_Renderer *renderer) override
    {
        if (fillColor != nullptr)
        {
            SDL_SetRenderDrawColor(renderer, fillColor->r, fillColor->g,
                                   fillColor->b, fillColor->a);

            SDL_RenderFillRectF(renderer, GetTransformedRect());
        }

        if (borderColor != nullptr)
        {
            SDL_SetRenderDrawColor(renderer, borderColor->r, borderColor->g,
                                   borderColor->b, borderColor->a);

            SDL_RenderDrawRectF(renderer, GetTransformedRect());
        }

        RenderObject::Render(renderer);
    }

    /**
     * Cleanup function to run after the RenderObject is unloaded.
     */
    void Clean() override {}
};

} // namespace Handcrank
