#include "../fonts/loader.h"

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/TextRenderObject.hpp"

using namespace Handcrank;

class FPS : public TextRenderObject
{

  public:
    void Start() override
    {
        LoadFontRW(fonts_Roboto_Roboto_Regular_ttf,
                   fonts_Roboto_Roboto_Regular_ttf_len, 30);
    }

    void Update(const double deltaTime) override
    {
        if (!game->HasFocus())
        {
            return;
        }

        SetText(std::to_string(game->GetFPS()));
    }
};
