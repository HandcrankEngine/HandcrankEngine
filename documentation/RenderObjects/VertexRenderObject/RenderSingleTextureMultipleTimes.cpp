#include "../images/sdl_logo.h"

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/ImageRenderObject.hpp"
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

        int textureWidth;
        int textureHeight;

        SDL_QueryTexture(texture, nullptr, nullptr, &textureWidth,
                         &textureHeight);

        for (auto x = 0; x < game->GetWidth(); x += textureWidth + 10)
        {
            for (auto y = 0; y < game->GetHeight(); y += textureHeight + 10)
            {
                GenerateTextureQuad(
                    vertices, indices,
                    {(float)x, (float)y, (float)textureWidth,
                     (float)textureHeight},
                    {0, 0, (float)textureWidth, (float)textureHeight},
                    {255, 255, 255, 255}, textureWidth, textureHeight);
            }
        }
    }
};

auto game = std::make_unique<Game>();

auto main(int argc, char *argv[]) -> int
{
    game->SetTitle("Handcrank Engine");

    game->AddChildObject(std::make_shared<LogoGrid>());

    return game->Run();
}
