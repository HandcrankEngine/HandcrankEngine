#include "../images/sdl_logo.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/Utilities.hpp"
#include "HandcrankEngine/VertexRenderObject.hpp"

using namespace HandcrankEngine;

class LogoGrid : public VertexRenderObject
{
  public:
    void Start() override
    {
        texture = LoadCachedTexture(game->GetRenderer(), images_sdl_logo_png,
                                    images_sdl_logo_png_len);

        float textureWidth;
        float textureHeight;

        SDL_GetTextureSize(texture, &textureWidth, &textureHeight);

        for (auto x = 0; x < game->GetWidth(); x += textureWidth + 10)
        {
            for (auto y = 0; y < game->GetHeight(); y += textureHeight + 10)
            {
                GenerateTextureQuad(
                    vertices, indices,
                    {(float)x, (float)y, textureWidth, textureHeight},
                    {0, 0, textureWidth, textureHeight}, {255, 255, 255, 255},
                    textureWidth, textureHeight);
            }
        }
    }
};

auto main(int argc, char *argv[]) -> int
{
    auto game = std::make_unique<Game>();

    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<LogoGrid>());

    return game->Run();
}
