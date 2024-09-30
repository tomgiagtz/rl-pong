#pragma once
#include "raylib.h"
#include "Core/Entity.h"
#include "Core/RectEntity.h"

class Ball : public RectEntity {
private:
    float speed = 500.f;

public:
    static constexpr int HEIGHT = 20;
    static constexpr int WIDTH = 20;

    void Start() override;
    void Update(float _deltaTime) override;
    Edge BoundsCollision();

    void OnCollisionBegin(RectEntity* _otherRect) override;
    void Reset();
    void RandomizeVelocity();
    void RandomizePosition();

    Ball(Vector2 _position) :
        RectEntity(_position, HEIGHT, WIDTH) {
        shouldCollide = true;
    };

private:
    void BounceOffEdge(Edge edge);
};
