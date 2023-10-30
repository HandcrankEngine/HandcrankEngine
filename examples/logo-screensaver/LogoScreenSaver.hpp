#include <algorithm>

#include "../images/sdl_logo.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/ImageRenderObject.hpp"

using namespace Handcrank;

int randomNumberRange(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

class LogoScreenSaver : public ImageRenderObject
{
  protected:
    int xDirection = rand() % 1 ? -1 : 1;
    int yDirection = rand() % 1 ? -1 : 1;

    int movementSpeed = rand() % 400 + 100;

  public:
    void Start() override
    {
        LoadTextureRW(game->GetRenderer(), images_sdl_logo_png,
                      images_sdl_logo_png_len);

        SetRect(randomNumberRange(0, game->GetWidth() - 200),
                randomNumberRange(0, game->GetWidth() - 200));
    }
    void Update(double deltaTime) override
    {
        if (!game->HasFocus())
        {
            return;
        }

        auto transformedRect = GetTransformedRect();

        auto rect = GetRect();

        auto minX = 0;
        auto minY = 0;

        auto maxX = game->GetWidth() - transformedRect->w;
        auto maxY = game->GetHeight() - transformedRect->h;

        rect->x += movementSpeed * xDirection * deltaTime;
        rect->y += movementSpeed * yDirection * deltaTime;

        if (rect->x > maxX || rect->x < minX)
        {
            xDirection = -xDirection;
        }

        if (rect->y > maxY || rect->y < minY)
        {
            yDirection = -yDirection;
        }

        rect->x = std::clamp<float>(rect->x, minX, maxX);
        rect->y = std::clamp<float>(rect->y, minY, maxY);
    }
};
