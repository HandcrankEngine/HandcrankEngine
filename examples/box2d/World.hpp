#include <box2d/box2d.h>

#include "HandcrankEngine/HandcrankEngine.hpp"

using namespace HandcrankEngine;

class World : public RenderObject
{
  private:
    int subStepCount = 4;
    float timeStep = 1.0f / 60.0f;

    b2WorldId worldId;

  public:
    using RenderObject::RenderObject;

    explicit World()
    {
        auto worldDef = b2DefaultWorldDef();
        worldDef.gravity = (b2Vec2){0.0f, -10.0f};
        worldId = b2CreateWorld(&worldDef);
    };

    auto GetWorldId() -> b2WorldId { return worldId; }

    void FixedUpdate(double deltaTime) override
    {
        b2World_Step(worldId, timeStep, subStepCount);
    }

    void OnDestroy() override { b2DestroyWorld(worldId); }
};
