# Animations

## Create an Animator

```cpp
#include "Handcrank/Animator.hpp"
#include "Handcrank/Handcrank.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    auto animator = std::make_shared<Animator>(Animator::Mode::SEQUENCE, true);

    animator->AddAnimation(std::make_shared<Animation>(
        [&](const double deltaTime, const double elapsedTime)
        {
            std::cout << elapsedTime << std::endl;

            return 1;
        }));

    game->AddChildObject(animator);

    return game->Run();
}
```

## Create a Blinking Animation

```cpp
#include "Handcrank/Animator.hpp"
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = std::make_unique<Game>();

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    auto cube = std::make_shared<RectRenderObject>(0, 0, 250, 250);

    cube->SetFillColor(MAX_R, 0, 0, 0);

    game->AddChildObject(cube);

    auto animator = std::make_shared<Animator>(Animator::Mode::SEQUENCE, true);

    float internalAlpha = 0;

    // Fade in
    animator->AddAnimation(std::make_shared<Animation>(
        [&](const double deltaTime, const double elapsedTime)
        {
            auto color = cube->GetFillColor();

            internalAlpha += 500 * deltaTime;

            auto alpha = std::clamp(internalAlpha, 0.0F, (float)MAX_ALPHA);

            cube->SetFillColor(color->r, color->g, color->b, alpha);

            return alpha == 255 ? 0 : 1;
        }));

    // Pause for 1 second
    animator->AddAnimation(std::make_shared<Animation>(
        [&](const double deltaTime, const double elapsedTime)
        { return elapsedTime > 1 ? 0 : 1; }));

    // Fade out
    animator->AddAnimation(std::make_shared<Animation>(
        [&](const double deltaTime, const double elapsedTime)
        {
            auto color = cube->GetFillColor();

            internalAlpha -= 500 * deltaTime;

            auto alpha = std::clamp(internalAlpha, 0.0F, (float)MAX_ALPHA);

            cube->SetFillColor(color->r, color->g, color->b, alpha);

            return alpha == 0 ? 0 : 1;
        }));

    // Pause for half a second
    animator->AddAnimation(std::make_shared<Animation>(
        [&](const double deltaTime, const double elapsedTime)
        { return elapsedTime > 0.5 ? 0 : 1; }));

    game->AddChildObject(animator);

    return game->Run();
}
```
