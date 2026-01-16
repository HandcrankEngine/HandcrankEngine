#pragma once

#include "HandcrankEngine/HandcrankEngine.hpp"

#include "World.hpp"
#include "WorldEntity.hpp"

using namespace HandcrankEngine;

class PhysicsDemo : public RenderObject
{
  public:
    void Start() override
    {
        auto world = std::make_shared<World>();

        game->AddChildObject(world);

        auto worldId = world->GetWorldId();

        world->AddChildObject(std::make_shared<WorldEntity>(
            worldId, b2_staticBody, 4.0f, 0.0f, 24.0f, 0.5f));
        world->AddChildObject(std::make_shared<WorldEntity>(
            worldId, b2_dynamicBody, 4.0f, 20, 1.0f, 1.0f));
        world->AddChildObject(std::make_shared<WorldEntity>(
            worldId, b2_dynamicBody, 4.0f, 15, 1.0f, 1.0f));
        world->AddChildObject(std::make_shared<WorldEntity>(
            worldId, b2_dynamicBody, 4.0f, 10, 1.0f, 1.0f));
    }
};
