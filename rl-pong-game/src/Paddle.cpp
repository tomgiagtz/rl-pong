#include "Paddle.h"
#include <iostream>

#include "raymath.h"


void Paddle::Start() {
    Entity::Start();
    // std::cout << "Paddle started" << std::endl;
    // Implementation for starting the Paddle
}

void Paddle::Update(float _deltaTime) {
    // Implementation for updating the Paddle with delta time
    if (playerType == PLAYER1 && IsKeyDown(KEY_RIGHT)) {
        position.x += 1.0f * speed;
    }
    if (playerType == PLAYER1 && IsKeyDown(KEY_LEFT)) {
        position.x -= 1.0f * speed;
    }

    if (playerType == PLAYER2 && IsKeyDown(KEY_D)) {
        position.x += 1.0f * speed;
    }
    if (playerType == PLAYER2 && IsKeyDown(KEY_A)) {
        position.x -= 1.0f * speed;
    }

    position.x = Clamp(position.x, float(GetScreenWidth() / 2.f), float(GetScreenWidth() - WIDTH));
}

void Paddle::Render() {
    // Implementation for rendering the Paddle
    DrawRectangle(position.x, position.y, WIDTH, HEIGHT, WHITE);
}
