#pragma once

#include "../images/Ghostscript_Tiger.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/ImageRenderObject.hpp"

using namespace HandcrankEngine;

class Tiger : public ImageRenderObject
{
  public:
    void Start() override
    {
        LoadTexture(game->GetRenderer(), images_Ghostscript_Tiger_svg,
                    images_Ghostscript_Tiger_svg_len);

        SetPosition(game->GetWidth() / 2, game->GetHeight() / 2);

        SetAnchor(RectAnchor::HCENTER | RectAnchor::VCENTER);
    }
};
