#include <box2d/box2d.h>

#include "HandcrankEngine/HandcrankEngine.hpp"
#include "HandcrankEngine/RectRenderObject.hpp"

using namespace HandcrankEngine;

class WorldEntity : public RenderObject
{

  private:
    float MetersToPixels = 100.0f;

    b2WorldId worldId;
    b2BodyDef bodyDef;
    b2BodyId bodyId;

    std::shared_ptr<RectRenderObject> rectRenderObject;

  public:
    using RenderObject::RenderObject;

    explicit WorldEntity(const b2WorldId worldId, b2BodyType type,
                         const float x, const float y, const float w,
                         const float h)
        : RenderObject(x, y, w, h)
    {
        this->worldId = worldId;

        bodyDef = b2DefaultBodyDef();
        bodyDef.type = type;
        bodyDef.fixedRotation = true;
        bodyDef.position = (b2Vec2){x, y};
        bodyId = b2CreateBody(worldId, &bodyDef);

        auto box = b2MakeBox(w / 2.0f, h / 2.0f);
        auto shapeDef = b2DefaultShapeDef();
        shapeDef.density = 1.0f;
        b2CreatePolygonShape(bodyId, &shapeDef, &box);

        rectRenderObject = std::make_shared<RectRenderObject>(
            0, 0, w * MetersToPixels, h * MetersToPixels);
        rectRenderObject->SetAnchor(RectAnchor::VCENTER | RectAnchor::HCENTER);
        rectRenderObject->SetFillColor({255, 255, 255, 255});
    };

    void Start() override { AddChildObject(rectRenderObject); }

    void FixedUpdate(double deltaTime) override
    {
        float horizon = game->GetHeight() / 2;

        b2Vec2 pos = b2Body_GetPosition(bodyId);
        rectRenderObject->SetPosition(pos.x * MetersToPixels,
                                      horizon - (pos.y * MetersToPixels));
    }
};
