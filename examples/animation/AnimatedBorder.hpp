#pragma once

#include "Handcrank/Animator.hpp"
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

class AnimatedBorder : public RenderObject
{
  private:
    std::shared_ptr<RectRenderObject> cube;

  public:
    void Start() override
    {
        cube = std::make_shared<RectRenderObject>(0, 0, 250, 250);

        cube->SetFillColor(255, 0, 0, 0);

        AddChildObject(cube);

        auto animator =
            std::make_shared<Animator>(Animator::Mode::SEQUENCE, true);

        // Fade in
        animator->AddAnimation(std::make_shared<Animation>(
            [&](const double deltaTime, const double elapsedTime)
            {
                auto color = cube->GetFillColor();

                auto alpha = color->a;

                alpha = std::clamp(color->a + 1, 0, 255);

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

                auto alpha = color->a;

                alpha = std::clamp(color->a - 1, 0, 255);

                cube->SetFillColor(color->r, color->g, color->b, alpha);

                return alpha == 0 ? 0 : 1;
            }));

        // Pause for half a second
        animator->AddAnimation(std::make_shared<Animation>(
            [&](const double deltaTime, const double elapsedTime)
            { return elapsedTime > 0.5 ? 0 : 1; }));

        game->AddChildObject(animator);
    }
};
