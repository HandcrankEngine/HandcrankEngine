#include "Handcrank/Game.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = new Game();

int main()
{
    game->SetTitle("Handcrank Engine");

    auto cube = std::make_unique<RectRenderObject>();

    SDL_Color colors[3] = {
        {255, 0, 0, 255}, {0, 255, 0, 255}, {0, 0, 255, 255}};

    const int colorIndexMax = sizeof(colors) / sizeof(colors[0]);

    int colorIndex = 0;

    cube->SetColor(colors[colorIndex]);

    cube->SetRect(0, 0, 200, 200);

    int xDirection = 1;
    int yDirection = 1;

    int movementSpeed = 10;

    cube->SetUpdate(
        [&xDirection, &yDirection, movementSpeed, colors, &colorIndex,
         colorIndexMax](GameObject *ref, double deltaTime)
        {
            if (!game->HasFocus())
            {
                return;
            }

            auto rectObj = dynamic_cast<RectRenderObject *>(ref);

            auto rect = rectObj->GetRect();

            rect->x += movementSpeed * xDirection;
            rect->y += movementSpeed * yDirection;

            if (rect->x > game->GetWidth() - rect->w || rect->x < 0)
            {
                colorIndex++;

                if (colorIndex > colorIndexMax - 1)
                {
                    colorIndex = 0;
                }

                rectObj->SetColor(colors[colorIndex]);

                xDirection = -xDirection;
            }

            if (rect->y > game->GetHeight() - rect->h || rect->y < 0)
            {
                colorIndex++;

                if (colorIndex > colorIndexMax - 1)
                {
                    colorIndex = 0;
                }

                rectObj->SetColor(colors[colorIndex]);

                yDirection = -yDirection;
            }
        });

    game->gameObjects.push_back(std::move(cube));

    return game->Run();
}
