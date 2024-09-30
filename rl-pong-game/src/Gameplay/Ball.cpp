#include "Ball.h"
#include "raymath.h"

void Ball::Start() {
    Entity::Start();
    Reset();
    // fill velocity with a random unit vector
}


void Ball::Update(const float _deltaTime) {
    Entity::Update(_deltaTime);
    if (IsKeyPressed(KEY_R)) {
        Reset();
    }
    Edge boundsCollision = BoundsCollision(this);
    if (boundsCollision != NONE) {
        BounceOffEdge(boundsCollision);
    }

    position = Vector2Add(position, Vector2Scale(velocity, speed * _deltaTime));
}

void Ball::OnCollisionBegin(RectEntity* _otherRect) {
    RectEntity::OnCollisionBegin(_otherRect);
    Edge edge = GetClosestEdge(this, _otherRect);

    BounceOffEdge(edge);
}

void Ball::Reset() {
    // velocity = Vector2Rotate(velocity, GetRandomValue(0, 360));
    // velocity = Vector2Normalize({1.f, 0.1f});
    // position = {GetScreenWidth() / 2.f, GetScreenHeight() / 2.f};
    SetColor({255, 255, 255, 255});
    RandomizeVelocity();
    RandomizePosition();
}

void Ball::RandomizeVelocity() {
    velocity = {0.f, 1.f};
    velocity = Vector2Rotate(velocity, (float)GetRandomValue(0, 360));
}

void Ball::BounceOffEdge(const Edge _edge) {
    if (_edge == TOP || _edge == BOTTOM) {
        velocity.y *= -1;
    }
    if (_edge == LEFT || _edge == RIGHT) {
        velocity.x *= -1;
    }
}
