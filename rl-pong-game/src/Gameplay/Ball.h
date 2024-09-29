#pragma once
#include "raylib.h"
#include "Core/Entity.h"
#include "Core/RectEntity.h"

enum CollisionType { NONE, EDGE, PADDLE, GOAL };

class Ball : public RectEntity {
    float speed = 500.f;

public:
    static constexpr int HEIGHT = 20;
    static constexpr int WIDTH = 20;

    void Start() override;
    void Update(float _deltaTime) override;
    CollisionType CalcCollision();
    void Render() override;


    void Reset();

    Ball(Vector2 _position) :
        RectEntity(_position, HEIGHT, WIDTH) {
        shouldCollide = true;
    };




};
