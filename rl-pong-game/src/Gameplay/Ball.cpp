#include "Ball.h"

#include "Paddle.h"
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

    if (dynamic_cast<Paddle*>(_otherRect) != nullptr) {
        BounceOffPaddle(_otherRect);
        return; // paddle bounce is authoritative; skip the generic edge flip
    }

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
    velocity = Vector2Rotate(velocity, (float) GetRandomValue(0, 360));
}

void Ball::BounceOffEdge(const Edge _edge) {
    if (_edge == TOP || _edge == BOTTOM) {
        velocity.y *= -1;
    }
    if (_edge == LEFT || _edge == RIGHT) {
        velocity.x *= -1;
    }
}
void Ball::BounceOffPaddle(RectEntity* _paddle) {
    // Where on the paddle's front face did we hit?
    // offset: -1 (top corner) .. 0 (center) .. +1 (bottom corner). raylib y is down.
    const float paddleHalfH = _paddle->GetHeight() / 2.f;
    const float paddleCenterY = _paddle->GetEdgeTop() + paddleHalfH;
    const float ballCenterY = GetEdgeTop() + HEIGHT / 2.f;
    float offset = (ballCenterY - paddleCenterY) / paddleHalfH;
    offset = Clamp(offset, -1.f, 1.f);

    // Deflection magnitude scales from MIN (center) to MAX (corner); the sign of
    // offset points it up (top) or down (bottom).
    const float magnitudeDeg = MIN_BOUNCE_ANGLE_DEG +
        fabsf(offset) * (MAX_BOUNCE_ANGLE_DEG - MIN_BOUNCE_ANGLE_DEG);
    const float angle = copysignf(magnitudeDeg, offset) * DEG2RAD;

    // Push the ball away from whichever side of the paddle it struck.
    const float paddleCenterX = _paddle->GetEdgeLeft() + _paddle->GetWidth() / 2.f;
    const float ballCenterX = GetEdgeLeft() + WIDTH / 2.f;
    const float xSign = (ballCenterX >= paddleCenterX) ? 1.f : -1.f;

    // velocity is a unit vector; `speed` supplies magnitude in Update().
    velocity = {xSign * cosf(angle), sinf(angle)};
}
