// Copyright (c) Scott Doxey. All Rights Reserved. Licensed under the MIT
// License. See LICENSE in the project root for license information.

#pragma once

#include <SDL.h>

#include "sdl/SDL_Utilities.hpp"

#include "Handcrank.hpp"

namespace Handcrank
{

class GeoRenderObject : public RenderObject
{
  private:
    SDL_Color color{255, 255, 255, 255};

  public:
    explicit GeoRenderObject() : RenderObject() {}
    explicit GeoRenderObject(SDL_FRect *_rect) : RenderObject(_rect) {}

    ~GeoRenderObject() = default;

    /**
     * Set rect color.
     * @param color Color value to set.
     */
    void SetColor(SDL_Color _color) { color = _color; }

    /**
     * Render geometry to the scene.
     */
    void Render(SDL_Renderer *renderer) override
    {
        SDL_Vertex vertices[] = {{{10.5, 10.5}, {255, 0, 0, 255}, {1, 1}},
                                 {{20.5, 10.5}, {255, 0, 0, 255}, {1, 1}},
                                 {{10.5, 20.5}, {255, 0, 0, 255}, {1, 1}}};

        auto texture =
            SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                              SDL_TEXTUREACCESS_STATIC, rect->w, rect->h);

        SDL_RenderGeometry(renderer, texture, vertices, 3, NULL, 0);

        SDL_RenderCopyExF(renderer, texture, nullptr, GetTransformedRect(), 45,
                          nullptr, SDL_FLIP_NONE);

        RenderObject::Render(renderer);
    }

    /**
     * Cleanup function to run after the RenderObject is unloaded.
     */
    void Clean() override {}
};

} // namespace Handcrank
