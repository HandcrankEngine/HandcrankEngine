// Copyright (c) Scott Doxey. All Rights Reserved. Licensed under the MIT
// License. See LICENSE in the project root for license information.

#pragma once

#include <SDL.h>

#include "sdl/SDL_Image_Utilities.hpp"

#include "Handcrank.hpp"

namespace Handcrank
{

class ImageRenderObject : public RenderObject
{
  private:
    std::shared_ptr<SDL_Texture> texture;

    const std::unique_ptr<SDL_Rect> srcRect;

    std::unique_ptr<SDL_FPoint> centerPoint = std::make_unique<SDL_FPoint>();

    SDL_RendererFlip flip = SDL_FLIP_NONE;

  public:
    explicit ImageRenderObject() {}
    explicit ImageRenderObject(const SDL_FRect _rect) { SetRect(_rect); }

    ~ImageRenderObject() = default;

    /**
     * Load texture from a path.
     *
     * @param renderer A structure representing rendering state.
     * @param path File path to texture file.
     *
     * @deprecated DEVELOPMENT USE ONLY! Use LoadTextureRW to load textures in a
     * release build.
     */
    void LoadTexture(std::shared_ptr<SDL_Renderer> renderer, const char *path)
    {
        texture = SDL_LoadTexture(renderer, path);

        UpdateRectSizeFromTexture();
    }

    /**
     * Load texture from a read-only buffer.
     *
     * @param renderer A structure representing rendering state.
     * @param mem A pointer to a read-only buffer.
     * @param size The buffer size, in bytes.
     */
    void LoadTextureRW(std::shared_ptr<SDL_Renderer> renderer, const void *mem,
                       const int size)
    {
        texture = SDL_LoadTextureRW(renderer, mem, size);

        UpdateRectSizeFromTexture();
    }

    void UpdateRectSizeFromTexture() const
    {
        int textureWidth;
        int textureHeight;

        SDL_QueryTexture(texture.get(), nullptr, nullptr, &textureWidth,
                         &textureHeight);

        rect->w = textureWidth;
        rect->h = textureHeight;
    }

    void SetSrcRect(const SDL_FRect srcRect)
    {
        this->srcRect->x = srcRect.x;
        this->srcRect->y = srcRect.y;
        this->srcRect->w = srcRect.w;
        this->srcRect->h = srcRect.h;
    }

    void SetSrcRect(const int x, const int y, const int w, const int h)
    {
        this->srcRect->x = x;
        this->srcRect->y = y;
        this->srcRect->w = w;
        this->srcRect->h = h;
    }

    void SetFlip(const SDL_RendererFlip flip) { this->flip = flip; }

    /**
     * Render image to the scene.
     *
     * @param renderer A structure representing rendering state.
     */
    void Render(std::shared_ptr<SDL_Renderer> renderer) override
    {
        auto transformedRect = GetTransformedRect();

        SDL_RenderCopyExF(renderer.get(), texture.get(), srcRect.get(),
                          &transformedRect, 0, centerPoint.get(), flip);

        RenderObject::Render(renderer);
    }
};

} // namespace Handcrank
