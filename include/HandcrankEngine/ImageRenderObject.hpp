// Copyright (c) Scott Doxey. All Rights Reserved. Licensed under the MIT
// License. See LICENSE in the project root for license information.

#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "HandcrankEngine.hpp"
#include "TextureRenderObject.hpp"

namespace HandcrankEngine
{

class ImageRenderObject : public TextureRenderObject
{
  protected:
    SDL_Texture *texture;

    SDL_FRect srcRect = SDL_FRect();

    bool srcRectSet = false;

    SDL_FPoint centerPoint = SDL_FPoint();

    SDL_Color tintColor = SDL_Color{MAX_R, MAX_G, MAX_B, MAX_ALPHA};

    int alpha = MAX_ALPHA;

    SDL_FlipMode flip = SDL_FLIP_NONE;

  public:
    explicit ImageRenderObject() = default;
    explicit ImageRenderObject(const float x, const float y)
        : TextureRenderObject(x, y) {};
    explicit ImageRenderObject(const float x, const float y, const float w,
                               const float h)
        : TextureRenderObject(x, y, w, h) {};

    ~ImageRenderObject() override = default;

    /**
     * Set texture from an existing texture reference.
     *
     * @param texture A texture.
     */
    void SetTexture(SDL_Texture *texture)
    {
        this->texture = texture;

        UpdateRectSizeFromTexture();
    }

    /**
     * Load texture from a path.
     *
     * @param renderer A structure representing rendering state.
     * @param path File path to texture file.
     *
     * @deprecated DEVELOPMENT USE ONLY! Use LoadTexture to load textures in a
     * release build.
     */
    void LoadTexture(SDL_Renderer *renderer, const char *path)
    {
        texture = LoadCachedTexture(renderer, path);

        UpdateRectSizeFromTexture();
    }

    /**
     * Load texture from a read-only buffer.
     *
     * @param renderer A structure representing rendering state.
     * @param mem A pointer to a read-only buffer.
     * @param size The buffer size, in bytes.
     */
    void LoadTexture(SDL_Renderer *renderer, const void *mem, const int size)
    {
        texture = LoadCachedTexture(renderer, mem, size);

        UpdateRectSizeFromTexture();
    }

    /**
     * Load SVG texture from a string.
     *
     * @param renderer A structure representing rendering state.
     * @param content Full SVG string including <svg></svg> tags.
     */
    void LoadSVGString(SDL_Renderer *renderer, const std::string &content)
    {
        texture = LoadCachedTexture(renderer, content.c_str(), content.size());

        UpdateRectSizeFromTexture();
    }

    void UpdateRectSizeFromTexture()
    {
        if (texture == nullptr)
        {
            return;
        }

        float textureWidth;
        float textureHeight;

        SDL_GetTextureSize(texture, &textureWidth, &textureHeight);

        rect.w = textureWidth;
        rect.h = textureHeight;
    }

    void SetSrcRect(const SDL_FRect &srcRect)
    {
        this->srcRect.x = srcRect.x;
        this->srcRect.y = srcRect.y;
        this->srcRect.w = srcRect.w;
        this->srcRect.h = srcRect.h;

        srcRectSet = true;
    }

    void SetSrcRect(const float x, const float y, const float w, const float h)
    {
        this->srcRect.x = x;
        this->srcRect.y = y;
        this->srcRect.w = w;
        this->srcRect.h = h;

        srcRectSet = true;
    }

    void SetFlip(const SDL_FlipMode flip) { this->flip = flip; }

    void SetTintColor(const SDL_Color &tintColor)
    {
        this->tintColor.r = tintColor.r;
        this->tintColor.g = tintColor.g;
        this->tintColor.b = tintColor.b;
    }

    void SetTintColor(const Uint8 r, const Uint8 g, const Uint8 b)
    {
        this->tintColor.r = r;
        this->tintColor.g = g;
        this->tintColor.b = b;
    }

    [[nodiscard]] auto GetTintColor() const -> const SDL_Color &
    {
        return tintColor;
    }

    void SetAlpha(const int alpha) { this->alpha = alpha; }

    [[nodiscard]] auto GetAlpha() const -> int { return alpha; }

    /**
     * Render image to the scene.
     *
     * @param renderer A structure representing rendering state.
     */
    void Render(SDL_Renderer *renderer) override
    {
        if (!CanRender() || texture == nullptr)
        {
            return;
        }

        auto transformedRect = GetTransformedRect();

        SDL_SetTextureColorMod(texture, tintColor.r, tintColor.g, tintColor.b);

        SDL_SetTextureAlphaMod(texture, alpha);

        SDL_RenderTextureRotated(renderer, texture,
                                 srcRectSet ? &srcRect : nullptr,
                                 &transformedRect, 0, &centerPoint, flip);

        RenderObject::Render(renderer);
    }
};

} // namespace HandcrankEngine
