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
        cube = std::make_shared<RectRenderObject>(0, 0, 0, 10);

        cube->SetFillColor(255, 0, 0, 255);

        AddChildObject(cube);

        animator = std::make_shared<Animator>(Animator::Mode::SEQUENCE, true);

        animator->AddAnimation(std::make_shared<Animation>(
            [&](const double deltaTime, const double elapsedTime)
            {
                cube->SetRect(0, game->GetHeight() - 10, 0, 10);

                return 0;
            }));

        animator->AddAnimation(std::make_shared<Animation>(
            [&](const double deltaTime, const double elapsedTime)
            {
                auto rect = cube->GetRect();

                auto width = rect->w;

                auto maxWidth = game->GetWidth();

                width = std::clamp(width + (500 * (float)deltaTime), 0.0F,
                                   (float)maxWidth);

                cube->SetRect(rect->x, rect->y, width, rect->h);

                return width == maxWidth ? 0 : 1;
            }));

        animator->AddAnimation(std::make_shared<Animation>(
            [&](const double deltaTime, const double elapsedTime)
            { return elapsedTime > 1 ? 0 : 1; }));

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
