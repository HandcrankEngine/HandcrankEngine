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

        assert(game->GetChildCount() == 0);

        auto renderObject = std::make_shared<RenderObject>();

        game->AddChildObject(renderObject);

        assert(game->GetChildCount() == 1);

        std::cout << ".";
    }

    {
        auto *game = new Game();

        auto renderObject = std::make_shared<RenderObject>();

        game->AddChildObject(renderObject);

        assert(game->GetChildCount() == 1);

        renderObject->Destroy();

        game->DestroyChildObjects();

        assert(game->GetChildCount() == 0);

        std::cout << ".";
    }

    return 0;
}
