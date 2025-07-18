// Copyright (c) Scott Doxey. All Rights Reserved. Licensed under the MIT
// License. See LICENSE in the project root for license information.

#pragma once

#include <SDL.h>

#include "Handcrank.hpp"

namespace Handcrank
{

class VertexRenderObject : public RenderObject
{
  protected:
    SDL_Texture *texture;

    std::vector<SDL_Vertex> vertices;
    std::vector<int> indices;

  public:
    void Render(SDL_Renderer *renderer) override
    {
        SDL_RenderGeometry(game->GetRenderer(), texture, vertices.data(),
                           vertices.size(), indices.data(), indices.size());

        RenderObject::Render(renderer);
    }
};

} // namespace Handcrank
