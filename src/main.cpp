#include "../fonts/Roboto/Roboto-Regular.h"

#include "Handcrank/Game.hpp"
#include "Handcrank/GameObject.hpp"
#include "Handcrank/RectRenderObject.hpp"
#include "Handcrank/TextRenderObject.hpp"

#include "Handcrank/sdl/SDL_TTF_Utilities.hpp"

using namespace Handcrank;

auto game = new Game();

int main()
{
    game->SetTitle("Handcrank Engine");

    auto logo = std::make_unique<GameObject>();

    logo->SetRect(0, 0, 200, 200);

    auto cube = std::make_unique<RectRenderObject>();

    auto text = std::make_unique<TextRenderObject>();

    auto font =
        SDL_TTF_Utilities::LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                                      fonts_Roboto_Roboto_Regular_ttf_len, 30);

    text->SetFont(font);

    text->SetRect(0, 0, logo->GetRect()->w, logo->GetRect()->h);

    text->SetWrappedText("Handcrank\nEngine");

    SDL_Color colors[3] = {
        {255, 0, 0, 255}, {0, 255, 0, 255}, {0, 0, 255, 255}};

    const int colorIndexMax = sizeof(colors) / sizeof(colors[0]);

    int colorIndex = 0;

    cube->SetColor(colors[colorIndex]);

    cube->SetRect(0, 0, logo->GetRect()->w, logo->GetRect()->h);

    logo->AddChildGameObject(std::move(cube));
    logo->AddChildGameObject(std::move(text));

    int xDirection = 1;
    int yDirection = 1;

    int movementSpeed = 10;

    logo->SetUpdate(
        [&xDirection, &yDirection, movementSpeed, colors, &colorIndex,
         colorIndexMax](GameObject *ref, double deltaTime)
        {
            if (!game->HasFocus())
            {
                return;
            }

            auto rect = ref->GetRect();

            auto cube = ref->GetChildByType<RectRenderObject>();

            rect->x += movementSpeed * xDirection;
            rect->y += movementSpeed * yDirection;

            if (rect->x > game->GetWidth() - rect->w || rect->x < 0)
            {
                colorIndex++;

                if (colorIndex > colorIndexMax - 1)
                {
                    colorIndex = 0;
                }

                cube->SetColor(colors[colorIndex]);

                xDirection = -xDirection;
            }

            if (rect->y > game->GetHeight() - rect->h || rect->y < 0)
            {
                colorIndex++;

                if (colorIndex > colorIndexMax - 1)
                {
                    colorIndex = 0;
                }

                cube->SetColor(colors[colorIndex]);

                yDirection = -yDirection;
            }
        });

    game->gameObjects.push_back(std::move(logo));

    return game->Run();
}
