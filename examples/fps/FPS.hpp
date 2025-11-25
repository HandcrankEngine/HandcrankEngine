#pragma once

#include <deque>
#include <numeric>

#include "../fonts/Roboto/Roboto-Regular.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"
#include "HandcrankEngine/TextRenderObject.hpp"

using namespace HandcrankEngine;

class FPS : public RenderObject
{
  private:
    std::shared_ptr<TextRenderObject> label =
        std::make_shared<TextRenderObject>();
    std::shared_ptr<RectRenderObject> background =
        std::make_shared<RectRenderObject>();

    std::shared_ptr<std::deque<int>> _frameRates =
        std::make_shared<std::deque<int>>();

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

    void Update(double deltaTime) override
    {
        if (!game->HasFocus())
        {
            return;
        }

        _frameRates->emplace_back(static_cast<int>(game->GetFPS()));

        if (_frameRates->size() > 100)
        {
            _frameRates->pop_front();
        }

        label->SetText(std::to_string(
            std::accumulate(_frameRates->begin(), _frameRates->end(), 0) /
            _frameRates->size()));

        auto backgroundRect = background->GetRect();

        background->SetRect(backgroundRect.x, backgroundRect.y,
                            label->GetRect().w + 25, backgroundRect.h);
    }
};
