#include <algorithm>

#include "../fonts/Roboto/Roboto-Regular.h"
#include "../images/sdl_logo.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/ImageRenderObject.hpp"
#include "Handcrank/RectRenderObject.hpp"
#include "Handcrank/TextRenderObject.hpp"

#include "Handcrank/sdl/SDL_TTF_Utilities.hpp"

using namespace Handcrank;

auto game = new Game();

auto font = SDL_TTF_Utilities::LoadFontRW(
    fonts_Roboto_Roboto_Regular_ttf, fonts_Roboto_Roboto_Regular_ttf_len, 30);

class Logo : public RenderObject
{
  protected:
    SDL_Color colors[3] = {
        {255, 0, 0, 255}, {0, 255, 0, 255}, {0, 0, 255, 255}};

    int colorIndex = 0;

    int colorIndexMax = 3;

    auto selectNextColor() -> SDL_Color
    {
        colorIndex++;

        if (colorIndex > colorIndexMax - 1)
        {
            colorIndex = 0;
        }

        return colors[colorIndex];
    }

    int xDirection = rand() % 1 ? -1 : 1;
    int yDirection = rand() % 1 ? -1 : 1;

    int movementSpeed = rand() % 400 + 100;

  public:
    void Update(double deltaTime) override
    {
        if (!game->HasFocus())
        {
            return;
        }

        auto transformedRect = GetTransformedRect();

        auto rect = GetRect();

        auto cube = GetChildByType<RectRenderObject>();

        auto minX = 0;
        auto minY = 0;

        auto maxX = game->GetWidth() - transformedRect->w;
        auto maxY = game->GetHeight() - transformedRect->h;

        rect->x += movementSpeed * xDirection * deltaTime;
        rect->y += movementSpeed * yDirection * deltaTime;

        if (rect->x > maxX || rect->x < minX)
        {
            xDirection = -xDirection;

            if (cube != nullptr)
            {
                cube->SetColor(selectNextColor());
            }
        }

        if (rect->y > maxY || rect->y < minY)
        {
            yDirection = -yDirection;

            if (cube != nullptr)
            {
                cube->SetColor(selectNextColor());
            }
        }

        rect->x = std::clamp<float>(rect->x, minX, maxX);
        rect->y = std::clamp<float>(rect->y, minY, maxY);
    }
};

class HandcrankLogo : public Logo
{
  public:
    void Start() override
    {
        SetScale(1.5);

        SetRect(rand() % game->GetWidth() - 200,
                rand() % game->GetWidth() - 200, 200, 200);

        auto cube = std::make_unique<RectRenderObject>();

        cube->SetColor(colors[colorIndex]);

        cube->SetRect(0, 0, GetRect()->w, GetRect()->h);

        AddChildObject(std::move(cube));

        auto text = std::make_unique<TextRenderObject>();

        text->SetFont(font);

        text->SetRect(0, 0, GetRect()->w, GetRect()->h);

        text->SetWrappedText("Handcrank\nEngine");

        AddChildObject(std::move(text));
    }
};

class SDL_Logo : public Logo
{
  public:
    void Start() override
    {
        auto image = std::make_unique<ImageRenderObject>();

        image->LoadTextureRW(game->GetRenderer(), images_sdl_logo_png,
                             images_sdl_logo_png_len);

        SetRect(rand() % game->GetWidth() - 200,
                rand() % game->GetWidth() - 200, image->GetRect()->w,
                image->GetRect()->h);

        AddChildObject(std::move(image));
    }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    auto framerateLabel = std::make_unique<TextRenderObject>();

    framerateLabel->SetFont(font);

    framerateLabel->z = 100;

    framerateLabel->SetText(std::to_string(0));

    framerateLabel->SetUpdate(
        [](RenderObject *ref, double deltaTime)
        {
            auto textRenderObject = dynamic_cast<TextRenderObject *>(ref);

            textRenderObject->SetText(std::to_string(game->GetFPS()));
        });

    game->AddChildObject(std::move(framerateLabel));

    game->AddChildObject(std::move(std::make_unique<HandcrankLogo>()));

    return game->Run();
}
