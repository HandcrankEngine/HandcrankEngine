#include "../fonts/Roboto/Roboto-Regular.h"

#include "Handcrank/Game.hpp"
#include "Handcrank/RectRenderObject.hpp"
#include "Handcrank/RenderObject.hpp"
#include "Handcrank/TextRenderObject.hpp"

#include "Handcrank/sdl/SDL_TTF_Utilities.hpp"

using namespace Handcrank;

auto game = new Game();

SDL_Color colors[3] = {{255, 0, 0, 255}, {0, 255, 0, 255}, {0, 0, 255, 255}};

const int colorIndexMax = sizeof(colors) / sizeof(colors[0]);

int colorIndex = 0;

auto selectNextColor() -> SDL_Color
{
    colorIndex++;

    if (colorIndex > colorIndexMax - 1)
    {
        colorIndex = 0;
    }

    return colors[colorIndex];
}

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    auto font =
        SDL_TTF_Utilities::LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                                      fonts_Roboto_Roboto_Regular_ttf_len, 30);

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

    auto logo = std::make_unique<RenderObject>();

    logo->SetScale(1.5);

    logo->SetRect(0, 0, 200, 200);

    auto cube = std::make_unique<RectRenderObject>();

    auto text = std::make_unique<TextRenderObject>();

    text->SetFont(font);

    text->SetRect(0, 0, logo->GetRect()->w, logo->GetRect()->h);

    text->SetWrappedText("Handcrank\nEngine");

    cube->SetColor(colors[colorIndex]);

    cube->SetRect(0, 0, logo->GetRect()->w, logo->GetRect()->h);

    logo->AddChildObject(std::move(cube));
    logo->AddChildObject(std::move(text));

    int xDirection = 1;
    int yDirection = 1;

    int movementSpeed = 500;

    logo->SetUpdate(
        [&xDirection, &yDirection, movementSpeed](RenderObject *ref,
                                                  double deltaTime)
        {
            if (!game->HasFocus())
            {
                return;
            }

            auto transformedRect = ref->GetTransformedRect();

            auto rect = ref->GetRect();

            auto cube = ref->GetChildByType<RectRenderObject>();

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
        });

    game->AddChildObject(std::move(logo));

    return game->Run();
}
