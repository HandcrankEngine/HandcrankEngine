#include <iostream>

#include "HandcrankEngine/HandcrankEngine.hpp"

using namespace HandcrankEngine;

class LoopDebugger : public RenderObject
{
  public:
    void Update(double deltaTime) override
    {
        std::cout << "Update " << std::to_string(deltaTime) << "\n";
    }

    void FixedUpdate(double fixedDeltaTime) override
    {
        std::cout << "Fixed Update " << std::to_string(fixedDeltaTime) << "\n";
    }
};

auto main(int argc, char *argv[]) -> int
{
    auto game = std::make_unique<Game>();

    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<LoopDebugger>());

    return game->Run();
}
