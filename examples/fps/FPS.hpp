#include "../fonts/Roboto/Roboto-Regular.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/TextRenderObject.hpp"

using namespace Handcrank;

class FPS : public TextRenderObject
{

  public:
    void Start() override
    {
        SetFontRW(fonts_Roboto_Roboto_Regular_ttf,
                  fonts_Roboto_Roboto_Regular_ttf_len, 30);
    }

    void Update(double deltaTime) override
    {
        SetText(std::to_string(game->GetFPS()));
    }
};
