#pragma once

#include "../images/alienGreen.h"

#include "HandcrankEngine/Handcrank.hpp"
#include "HandcrankEngine/SpriteRenderObject.hpp"

using namespace Handcrank;

class GreenAlien : public SpriteRenderObject
{
  public:
    void Start() override
    {
        LoadTexture(game->GetRenderer(), images_alienGreen_png,
                    images_alienGreen_png_len);

        SetPosition(game->GetWidth() / 2, game->GetHeight() / 2);

        SetAnchor(RectAnchor::HCENTER | RectAnchor::VCENTER);

        SetScale(2);

        SetFrameSpeed(0.25);

        AddFrame({69, 193, 68, 93});
        AddFrame({0, 0, 70, 96});

        Play();
    }
};
