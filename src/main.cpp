#include <box2d/box2d.h>

#include "Handcrank/Handcrank.hpp"
#include "Handcrank/RectRenderObject.hpp"

using namespace Handcrank;

auto game = new Game();

auto main() -> int
{
    game->SetTitle("Handcrank Engine");

    b2Vec2 gravity(0.0f, -9.8f);
    b2World world(gravity);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    b2Body *body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(50.0f, 50.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    auto box = std::make_unique<RectRenderObject>();

    box->SetFillColor(255, 0, 0, 255);

    box->SetFixedUpdate(
        [&world, &body](RenderObject *ref, double deltaTime)
        {
            ref->SetRect(body->GetPosition().x, -body->GetPosition().y);

            world.Step(1.0f / 60.0f, 6, 2);
        });

    game->AddChildObject(std::move(box));

    return game->Run();
}
