#include <iostream>

#include "HandcrankEngine/Animator.hpp"
#include "HandcrankEngine/HandcrankEngine.hpp"

using namespace HandcrankEngine;

auto game = std::make_unique<Game>();

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    auto animator = std::make_shared<Animator>(Animator::Mode::SEQUENCE, true);

    animator->AddAnimation(std::make_shared<Animation>(
        [&](double deltaTime, double elapsedTime)
        {
            std::cout << elapsedTime << std::endl;

            return 1;
        }));

    game->AddChildObject(animator);

    return game->Run();
}
