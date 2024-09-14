#pragma once
#include "raylib.h"
#include "Core/Entity.h"

enum CollisionType { NONE, EDGE, PADDLE, GOAL };

class Ball : public Entity {
private:
    Vector2 position;
    Vector2 velocity = {1, 0};

    float speed = 300.f;

public:
    static constexpr int HEIGHT = 120;
    static constexpr int WIDTH = 200;

    void Start() override;
    void Update(float _deltaTime) override;
    CollisionType CalcCollision();
    void Render() override;


    void Reset();

    Ball(Vector2 _position) :
        position(_position) {}



};
