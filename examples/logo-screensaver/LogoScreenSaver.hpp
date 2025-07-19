#pragma once

#include "../fonts/Roboto/Roboto-Regular.h"
#include "../images/sdl_logo.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/ImageRenderObject.hpp"
#include "Handcrank/RectRenderObject.hpp"
#include "Handcrank/TextRenderObject.hpp"
#include "Handcrank/Utilities.hpp"
#include "Handcrank/VertexRenderObject.hpp"

using namespace Handcrank;

class LogoScreenSaver : public VertexRenderObject
{
    struct Item
    {
        SDL_FRect rect;
        SDL_FRect srcRect;
        SDL_Color color;
        int xDirection;
        int yDirection;
        int speed;
    };

  private:
    std::shared_ptr<TextRenderObject> label =
        std::make_shared<TextRenderObject>();
    std::shared_ptr<RectRenderObject> background =
        std::make_shared<RectRenderObject>();

    std::vector<Item> items;

    SDL_Color currentColor = {255, 255, 255, 255};

    int textureWidth;
    int textureHeight;

  public:
    void Start() override
    {
        AddChildObject(background);

        background->SetRect({(float)game->GetWidth() - 200,
                             (float)game->GetHeight() - 125, 200, 70});
        background->SetFillColor({255, 255, 255, 255});

        background->z = 1;

        label->SetRect({10, 10});
        label->LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                          fonts_Roboto_Roboto_Regular_ttf_len, 40);

        label->SetColor({0, 0, 0, 255});

        label->SetText("0");

        background->AddChildObject(label);

        texture = LoadCachedTexture(game->GetRenderer(), images_sdl_logo_png,
                                    images_sdl_logo_png_len);

        int length = 100000;

        items.reserve(length);

        vertices.reserve(length * 4);
        indices.reserve(length * 6);

        SDL_QueryTexture(texture, nullptr, nullptr, &textureWidth,
                         &textureHeight);

        for (auto i = 0; i < length; i += 1)
        {
            auto x = RandomNumberRange(0, game->GetWidth() - textureWidth);
            auto y = RandomNumberRange(0, game->GetHeight() - textureHeight);

            AddLogoToList(x, y);
        }
    }

    void Update(double deltaTime) override
    {
        if (game->IsMouseButtonPressed(SDL_BUTTON_LEFT))
        {
            currentColor.r = RandomBoolean() ? 255 : 100;
            currentColor.g = RandomBoolean() ? 255 : 100;
            currentColor.b = RandomBoolean() ? 255 : 100;
        }

        if (game->IsMouseButtonDown(SDL_BUTTON_LEFT))
        {
            AddLogoToList(game->GetMousePosition().x - (textureWidth / 2),
                          game->GetMousePosition().y - (textureHeight / 2));
        }

        if (game->IsKeyPressed(SDLK_c))
        {
            items.clear();

            label->SetText("0");

            vertices.clear();
            indices.clear();
        }

        if (!game->HasFocus())
        {
            return;
        }

        const auto minX = 0;
        const auto minY = 0;

        const auto maxX = game->GetWidth() - textureWidth;
        const auto maxY = game->GetHeight() - textureHeight;

        for (int i = 0; i < items.size(); ++i)
        {
            auto &item = items[i];

            float x = item.rect.x + (item.speed * item.xDirection * deltaTime);
            float y = item.rect.y + (item.speed * item.yDirection * deltaTime);

            if (x > maxX || x < minX)
            {
                items[i].xDirection = -item.xDirection;
            }

            if (y > maxY || y < minY)
            {
                items[i].yDirection = -item.yDirection;
            }

            items[i].rect.x = std::clamp<float>(x, minX, maxX);
            items[i].rect.y = std::clamp<float>(y, minY, maxY);

            UpdateTextureQuad(vertices.data() + (i * 4), (i * 4), item.rect);
        }
    }

  private:
    void AddLogoToList(float x, float y)
    {
        items.emplace_back(Item{
            {(float)x, (float)y, (float)textureWidth, (float)textureHeight},
            {0, 0, (float)textureWidth, (float)textureHeight},
            currentColor,
            RandomBoolean() ? -1 : 1,
            RandomBoolean() ? -1 : 1,
            (rand() % 400) + 100});

        GenerateTextureQuad(vertices, indices, items.back().rect,
                            items.back().srcRect, items.back().color,
                            textureWidth, textureHeight);

        label->SetText(std::to_string(items.size()));
    }
};
