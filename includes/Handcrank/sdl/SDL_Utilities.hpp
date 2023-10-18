// Copyright (c) Scott Doxey. All Rights Reserved. Licensed under the MIT
// License. See LICENSE in the project root for license information.

#pragma once

#include <SDL.h>

extern SDL_FRect *PositionRect(SDL_FRect *rect, SDL_FRect *parent)
{
    return new SDL_FRect{rect->x + parent->x, rect->y + parent->y, rect->w,
                         rect->h};
}

extern SDL_FRect *ScaleRect(SDL_FRect *rect, float scale)
{
    return new SDL_FRect{rect->x, rect->y, rect->w * scale, rect->h * scale};
}

struct SDL_TextureDeleter
{
    void operator()(SDL_Texture *texture) const
    {
        if (texture)
        {
            SDL_DestroyTexture(texture);
        }
    }
};

extern void RenderGeo(SDL_Renderer *renderer, SDL_FRect *rect,
                      SDL_Vertex *vertices, SDL_Color color)
{
    std::unique_ptr<SDL_Texture, SDL_TextureDeleter> texture(
        SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                          SDL_TEXTUREACCESS_STATIC, 500, 500));

    SDL_RenderGeometry(renderer, texture.get(), vertices, 3, nullptr, 0);

    SDL_RenderFillRectF(renderer, rect);
}
