// Copyright (c) Scott Doxey. All Rights Reserved. Licensed under the MIT
// License. See LICENSE in the project root for license information.

#pragma once

#include <string>

#include <SDL.h>
#include <SDL_ttf.h>

#include "sdl/SDL_TTF_Utilities.hpp"

#include "Handcrank.hpp"

namespace Handcrank
{

class TextRenderObject : public RenderObject
{
  private:
    std::shared_ptr<TTF_Font> font;

    SDL_Color color{255, 255, 255, 255};

    std::string text;

    std::shared_ptr<SDL_Surface> textSurface;

    std::shared_ptr<SDL_Texture> textTexture;

  public:
    explicit TextRenderObject()
    {
        if (!TTF_WasInit())
        {
            TTF_Init();
        }
    }
    explicit TextRenderObject(const SDL_FRect _rect) { SetRect(_rect); }

    /**
     * Set text font.
     *
     * @param font Font value to set.
     */
    void SetFont(std::shared_ptr<TTF_Font> font) { this->font = font; }

    /**
     * Load font from a path.
     *
     * @param path File path to font file.
     * @param ptSize The size of the font.
     *
     * @deprecated DEVELOPMENT USE ONLY! Use SDL_LoadFontRW to load
     * fonts in a release build.
     */
    void LoadFont(const char *path, const int ptSize = 24)
    {
        font = SDL_LoadFont(path, ptSize);
    }

    /**
     * Load font from a read-only buffer.
     *
     * @param mem A pointer to a read-only buffer.
     * @param size The buffer size, in bytes.
     * @param ptSize The size of the font.
     */
    void LoadFontRW(const void *mem, const int size, const int ptSize = 24)
    {
        font = SDL_LoadFontRW(mem, size, ptSize);
    }

    /**
     * Set text color.
     *
     * @param color Color value to set.
     */
    void SetColor(const SDL_Color color) { this->color = color; }

    /**
     * Set text content.
     *
     * @param text Text value to set.
     */
    void SetText(std::string text)
    {
        this->text = std::move(text);

        if (font == nullptr)
        {
            std::cerr << "ERROR! Missing font reference." << std::endl;

            return;
        }

        textSurface = std::shared_ptr<SDL_Surface>(
            TTF_RenderText_Blended(font.get(), this->text.c_str(), color),
            SDL_FreeSurface);

        rect->w = textSurface->w;
        rect->h = textSurface->h;

        textTexture = nullptr;
    }

    /**
     * Set text content.
     *
     * @param text Text value to set.
     */
    void SetWrappedText(std::string text)
    {
        this->text = text;

        textSurface = std::shared_ptr<SDL_Surface>(
            TTF_RenderText_Blended_Wrapped(font.get(), text.c_str(), color,
                                           rect->w),
            SDL_FreeSurface);

        rect->w = textSurface->w;
        rect->h = textSurface->h;

        textTexture = nullptr;
    }

    std::string GetText() { return text; }

    /**
     * Render text to the scene.
     *
     * @param renderer A structure representing rendering state.
     */
    void Render(std::shared_ptr<SDL_Renderer> renderer) override
    {
        if (textTexture == nullptr)
        {
            textTexture = std::shared_ptr<SDL_Texture>(
                SDL_CreateTextureFromSurface(renderer.get(), textSurface.get()),
                SDL_DestroyTexture);
        }

        auto transformedRect = GetTransformedRect();

        SDL_RenderCopyF(renderer.get(), textTexture.get(), nullptr,
                        &transformedRect);

        RenderObject::Render(renderer);
    }
};

} // namespace Handcrank
