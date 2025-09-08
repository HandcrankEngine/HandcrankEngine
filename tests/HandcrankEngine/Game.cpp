#include <cassert>
#include <iostream>

#include "HandcrankEngine/HandcrankEngine.hpp"

using namespace HandcrankEngine;

auto main(int argc, char *argv[]) -> int
{

    {
        auto *game = new Game();

        std::cout << ".";
    }

    {
        auto *game = new Game();

        assert(size(game->children) == 0);

        auto renderObject = std::make_shared<RenderObject>();

        game->AddChildObject(renderObject);

        assert(size(game->children) == 1);

        std::cout << ".";
    }

    {
        auto *game = new Game();

        auto renderObject = std::make_shared<RenderObject>();

        game->AddChildObject(renderObject);

        assert(size(game->children) == 1);

        renderObject->Destroy();

        game->DestroyChildObjects();

        assert(size(game->children) == 0);

        std::cout << ".";
    }

    return 0;
}
