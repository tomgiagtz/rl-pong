#include "Ball.h"

#include "raymath.h"



void Ball::Start() {
    Entity::Start();
    Reset();
    // fill velocity with a random unit vector
}

void Ball::Update(float _deltaTime) {
    Entity::Update(_deltaTime);
    if (IsKeyDown(KEY_R)) {
        Reset();
    }

    switch (CalcCollision()) {
    case EDGE:
        velocity.y *= -1;
        break;
    case PADDLE:
        break;
    case GOAL:
        velocity.x *= -1;
        break;
    case NONE:
        break;
    }


    // pos += vel * speed * deltaTime;
    position = Vector2Add(position, Vector2Scale(velocity, speed * _deltaTime));
}


CollisionType Ball::CalcCollision() {
    //check vertical boundary (EDGE)
    if (position.y >= GetScreenHeight() - HEIGHT || position.y <= 0) {
        return EDGE;
    }
    //check for Horizontal boundary (GOAL)
    if (position.x >= GetScreenWidth() - WIDTH || position.x <= 0) {
        return GOAL;
    }
    // check for PaddleCollision
    return NONE;
}

void Ball::Render() {
    Entity::Render();

    DrawRectangleV(position, {WIDTH, HEIGHT}, WHITE);
}

void Ball::Reset() {
    velocity = Vector2Rotate(velocity, GetRandomValue(0, 360));
    position = {GetScreenWidth() / 2.f, GetScreenHeight() / 2.f};
}
