#pragma once

#include "Handcrank/Animator.hpp"
#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

class AnimatedBorder : public RenderObject
{
  private:
    std::shared_ptr<RectRenderObject> cube;
    std::shared_ptr<Animator> animator;

  public:
    void Start() override
    {
        cube = std::make_shared<RectRenderObject>(0, 0, 250, 250);

        cube->SetFillColor(255, 0, 0, 0);

        AddChildObject(cube);

        animator = std::make_shared<Animator>(Animator::Mode::PARALLEL, true);

        animator->AddAnimation(std::make_shared<Animation>(
            [&](const double deltaTime, const double elapsedTime)
            {
                cube->SetFillColor(255, 0, 0, 0);

                cube->SetRect(0, 0);

                return 0;
            }));

        animator->AddAnimation(std::make_shared<Animation>(
            [&](const double deltaTime, const double elapsedTime)
            {
                auto color = cube->GetFillColor();

                auto alpha = color->a;

                alpha = std::clamp(alpha + 1, 0, 255);

                cube->SetFillColor(color->r, color->g, color->b, alpha);

                return alpha == 255 ? 0 : 1;
            }));

        animator->AddAnimation(std::make_shared<Animation>(
            [&](const double deltaTime, const double elapsedTime)
            {
                auto rect = cube->GetRect();

                auto x = rect->x;

                auto maxX = game->GetWidth() - rect->w;

                x = std::clamp(x + 1, 0.0F, maxX);

                cube->SetRect(x, rect->y);

                return x == maxX ? 0 : 1;
            }));

        game->AddChildObject(animator);
    }

    void Update(const double deltaTime) override
    {
        if (!game->HasFocus())
        {
            animator->Pause();

            return;
        }

        animator->Resume();
    }
};
