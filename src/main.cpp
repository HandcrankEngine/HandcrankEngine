#include <algorithm>

#include "../fonts/Roboto/Roboto-Regular.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"
#include "Handcrank/TextRenderObject.hpp"

#include "Handcrank/sdl/SDL_TTF_Utilities.hpp"

using namespace Handcrank;

auto game = new Game();

auto font = SDL_TTF_Utilities::LoadFontRW(
    fonts_Roboto_Roboto_Regular_ttf, fonts_Roboto_Roboto_Regular_ttf_len, 30);

class Logo : public RenderObject
{
  private:
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

    int xDirection = 1;
    int yDirection = 1;

    int movementSpeed = 500;

  public:
    void Start() override
    {
        SetScale(1.5);

        SetRect(0, 0, 200, 200);

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

    void Update(double deltaTime) override
    {
        if (!game->HasFocus())
        {
            return;
        }

        auto transformedRect = GetTransformedRect();

        auto rect = GetRect();

        auto cube = GetChildByType<RectRenderObject>();

        auto maxX = game->GetWidth() - transformedRect->w;
        auto maxY = game->GetHeight() - transformedRect->h;

        rect->x += movementSpeed * xDirection * deltaTime;
        rect->y += movementSpeed * yDirection * deltaTime;

        if (rect->x > maxX || rect->x < 0)
        {
            xDirection = -xDirection;

            if (cube != nullptr)
            {
                cube->SetColor(selectNextColor());
            }
        }

        if (rect->y > maxY || rect->y < 0)
        {
            yDirection = -yDirection;

            if (cube != nullptr)
            {
                cube->SetColor(selectNextColor());
            }
        }

        rect->x = std::clamp<float>(rect->x, 0, maxX);
        rect->y = std::clamp<float>(rect->y, 0, maxY);
    }
};

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    auto framerateLabel = std::make_unique<TextRenderObject>();

    framerateLabel->SetFont(font);

    framerateLabel->SetText(std::to_string(0));

    framerateLabel->SetUpdate(
        [](RenderObject *ref, double deltaTime)
        {
            auto textRenderObject = dynamic_cast<TextRenderObject *>(ref);

            textRenderObject->SetText(std::to_string(1.0 / deltaTime));
        });

    game->AddChildObject(std::move(framerateLabel));

    auto logo = std::make_unique<Logo>();

    game->AddChildObject(std::move(logo));

    return game->Run();
}
