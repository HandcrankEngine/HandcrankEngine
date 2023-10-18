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

auto main() -> int
{
    if (!game->Setup())
    {
        return 1;
    }

    while (!game->GetQuit())
    {
        game->HandleInput();

        auto renderer = game->GetRenderer();

        SDL_Vertex vertex_1 = {{140, 23}, {255, 0, 0, 255}, {1, 1}};
        SDL_Vertex vertex_2 = {{232, 178}, {255, 0, 0, 255}, {1, 1}};
        SDL_Vertex vertex_3 = {{47, 178}, {255, 0, 0, 255}, {1, 1}};

        SDL_Vertex vertices[] = {vertex_1, vertex_2, vertex_3};

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        RenderGeo(renderer, nullptr, vertices, {255, 0, 0, 255});

        SDL_RenderPresent(renderer);

        SDL_Delay(1);
    }

    game->Clean();

    return 0;
}
