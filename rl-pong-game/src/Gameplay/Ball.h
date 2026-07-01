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
    // Paddle bounce deflection band: 5deg at center -> 85deg at the corners.
    static constexpr float MIN_BOUNCE_ANGLE_DEG = 5.f;
    static constexpr float MAX_BOUNCE_ANGLE_DEG = 85.f;

    void Start() override;
    void Update(float _deltaTime) override;

    void OnCollisionBegin(RectEntity* _otherRect) override;
    void Reset();
    void RandomizeVelocity();

    Ball(Vector2 _position) :
        RectEntity(_position, HEIGHT, WIDTH) {
        shouldCollide = true;
    };

private:
    void BounceOffEdge(Edge _edge);
    void BounceOffPaddle(RectEntity* _paddle);
};
