#include "Ball.h"

#include "raymath.h"



void Ball::BounceOffEdge(Edge edge) {
    if (edge == TOP || edge == BOTTOM) {
        velocity.y *= -1;
    }
    if (edge == LEFT || edge == RIGHT) {
        velocity.x *= -1;
    }
}

void Ball::OnCollisionBegin(RectEntity* _otherRect) {
    RectEntity::OnCollisionBegin(_otherRect);
    Edge edge = GetClosestEdge(this, _otherRect);

    BounceOffEdge(edge);
}

void Ball::Start() {
    Entity::Start();
    Reset();
    // fill velocity with a random unit vector
}

void Ball::Update(float _deltaTime) {
    Entity::Update(_deltaTime);
    if (IsKeyPressed(KEY_R)) {
        Reset();
    }
    Edge boundsCollision = BoundsCollision();
    if (boundsCollision != NONE) {
        BounceOffEdge(boundsCollision);
    }

    position = Vector2Add(position, Vector2Scale(velocity, speed * _deltaTime));
}


Edge Ball::BoundsCollision() {
    if (position.y <= 0) return TOP;
    if (position.y >= GetScreenHeight() - HEIGHT) return BOTTOM;
    if (position.x <= 0) return LEFT;
    if (position.x >= GetScreenWidth() - WIDTH) return RIGHT;
    return NONE;
}

void Ball::Reset() {
    // velocity = Vector2Rotate(velocity, GetRandomValue(0, 360));
    // velocity = Vector2Normalize({1.f, 0.1f});
    // position = {GetScreenWidth() / 2.f, GetScreenHeight() / 2.f};
    RandomizeVelocity();
    RandomizePosition();
}

void Ball::RandomizeVelocity() {
    velocity = {0.f, 1.f};
    velocity = Vector2Rotate(velocity, GetRandomValue(0, 360));
}

void Ball::RandomizePosition() {
    float xpos = GetRandomValue(0, GetScreenWidth() - WIDTH);
    float ypos = GetRandomValue(0, GetScreenHeight() - HEIGHT);
    position = {xpos, ypos};
}
