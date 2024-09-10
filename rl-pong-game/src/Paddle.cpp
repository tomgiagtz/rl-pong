#include "Paddle.h"
#include <iostream>

void Paddle::Start() {
    // Implementation for starting the Paddle
}

void Paddle::Update(float _deltaTime) {
    // std::cout << "UPDATE HOLY Entity \n";
    // Implementation for updating the Paddle with delta time
    if (IsKeyDown(KEY_RIGHT)) {
        position.x += 1.0f * speed;
    }
    if (IsKeyDown(KEY_LEFT)) {
        position.x -= 1.0f * speed;
    }
}

void Paddle::Render() {
    // Implementation for rendering the Paddle
    std::cout << "Rendering Entity \n";
    DrawRectangle(position.x, position.y, width, height, WHITE);
}
