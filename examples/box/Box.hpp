#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

class Box : public RectRenderObject
{

  public:
    void Start() override
    {
        SetFillColor(255, 255, 255, 255);
        SetRect(game->GetWidth() - 125, game->GetHeight() - 125, 100, 100);
    }
};
