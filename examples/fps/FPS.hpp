#pragma once

#include "../fonts/Roboto/Roboto-Regular.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"
#include "Handcrank/TextRenderObject.hpp"

using namespace Handcrank;

class FPS : public RenderObject
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

        background->SetRect({0, 0, 70, 70});
        background->SetFillColor({255, 255, 255, 255});

        label->SetRect({10, 10});
        label->LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                          fonts_Roboto_Roboto_Regular_ttf_len, 40);

        label->SetColor({0, 0, 0, 255});

        background->AddChildObject(label);
    }

    void Update(const double deltaTime) override
    {
        if (!game->HasFocus())
        {
            return;
        }

        label->SetText(std::to_string(static_cast<int>(game->GetFPS())));
    }
};
