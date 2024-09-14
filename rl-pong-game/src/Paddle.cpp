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

    int calcSpeed = 10 * speed * _deltaTime;
    if (playerType == PLAYER2 && IsKeyDown(KEY_UP)) {
        position.y -= calcSpeed;
    }
    if (playerType == PLAYER2 && IsKeyDown(KEY_DOWN)) {
        position.y += calcSpeed;
    }

    if (playerType == PLAYER1 && IsKeyDown(KEY_W)) {
        position.y -= calcSpeed;
    }
    if (playerType == PLAYER1 && IsKeyDown(KEY_S)) {
        position.y += calcSpeed;
    }

    position.y = Clamp(position.y, 0, float(GetScreenHeight() - HEIGHT));
}

void Paddle::Render() {
    // Implementation for rendering the Paddle
    DrawRectangle(position.x, position.y, WIDTH, HEIGHT, WHITE);
}
