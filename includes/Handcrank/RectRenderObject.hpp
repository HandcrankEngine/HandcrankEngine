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
    double rotation;

  private:
    SDL_Color *borderColor;
    SDL_Color *fillColor;

    SDL_BlendMode blendMode = SDL_BLENDMODE_BLEND;

    SDL_Texture *tempRenderTexture;

  public:
    explicit RectRenderObject() {}
    explicit RectRenderObject(SDL_FRect *rect) : RenderObject(rect) {}

    ~RectRenderObject() = default;

    /**
     * Set rect border color.
     *
     * @param borderColor Color value to set.
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

    /**
     * Set rect fill color.
     *
     * @param fillColor Color value to set.
     */
    void SetFillColor(const SDL_Color fillColor)
    {
        if (this->fillColor == nullptr)
        {
            this->fillColor = new SDL_Color();
        }

        this->fillColor->r = fillColor.r;
        this->fillColor->g = fillColor.g;
        this->fillColor->b = fillColor.b;
        this->fillColor->a = fillColor.a;
    }

    void SetFillColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
    {
        if (fillColor == nullptr)
        {
            fillColor = new SDL_Color();
        }

        fillColor->r = r;
        fillColor->g = g;
        fillColor->b = b;
        fillColor->a = a;
    }

    SDL_Color *GetFillColor() const
    {
        if (fillColor == nullptr)
        {
            return nullptr;
        }

        return fillColor;
    }

    /**
     * Render rect to the scene.
     *
     * @param renderer A structure representing rendering state.
     */
    void Render(SDL_Renderer *renderer) override
    {
        SDL_SetRenderDrawBlendMode(renderer, blendMode);

        if (rotation != 0)
        {
            tempRenderTexture =
                SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                  SDL_TEXTUREACCESS_TARGET, rect->w, rect->h);

            SDL_SetRenderTarget(renderer, tempRenderTexture);

            std::cout << "temp" << std::endl;
        }

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

        if (rotation != 0)
        {
            SDL_SetRenderTarget(renderer, nullptr);

            SDL_RenderCopyExF(renderer, tempRenderTexture, nullptr,
                              GetTransformedRect(), rotation, nullptr,
                              SDL_FLIP_NONE);
        }
    }

    /**
     * Cleanup function to run after the RectRenderObject is unloaded.
     */
    void Clean() override {}
};

} // namespace Handcrank
