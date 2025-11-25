#pragma once

#include "../fonts/Roboto/Roboto-Regular.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"
#include "HandcrankEngine/TextRenderObject.hpp"

using namespace HandcrankEngine;

class PausedScreen : public RenderObject
{
  private:
    std::shared_ptr<TextRenderObject> label =
        std::make_shared<TextRenderObject>();
    std::shared_ptr<RectRenderObject> background =
        std::make_shared<RectRenderObject>();

  public:
    void Start() override
    {
        AddChildObject(background);

        background->SetRect(
            {0, 0, (float)game->GetWidth(), (float)game->GetHeight()});
        background->SetFillColor({0, 0, 0, 200});

        label->SetAnchor(RectAnchor::HCENTER | RectAnchor::VCENTER);

        label->SetRect(
            {(float)game->GetWidth() / 2, (float)game->GetHeight() / 2});
        label->LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                          fonts_Roboto_Roboto_Regular_ttf_len, 100);

        label->SetColor({255, 255, 255, 255});

        label->SetText("Paused");

        background->AddChildObject(label);

        background->Disable();
    }

    void Update(double deltaTime) override
    {
        if (game->HasFocus() && background->IsEnabled())
        {
            background->Disable();
        }
        else if (!game->HasFocus() && !background->IsEnabled())
        {
            background->Enable();
        }
    }
};
