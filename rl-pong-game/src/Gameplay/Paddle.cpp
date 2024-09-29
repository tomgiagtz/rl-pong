#include "Paddle.h"
#include <iostream>

#include "raymath.h"
#include "Core/RectEntity.h"


void Paddle::Start() {
    RectEntity::Start();


    // std::cout << "Paddle started" << std::endl;
    // Implementation for starting the Paddle
}

void Paddle::Update(float _deltaTime) {
    // Implementation for updating the Paddle with delta time
    if (this->controlType == None) return;

    int calcSpeed = 10 * speed * _deltaTime;
    if (controlType == Player2 && IsKeyDown(KEY_UP)) {
        position.y -= calcSpeed;
    }
    if (controlType == Player2 && IsKeyDown(KEY_DOWN)) {
        position.y += calcSpeed;
    }

    if (controlType == Player1 && IsKeyDown(KEY_W)) {
        position.y -= calcSpeed;
    }
    if (controlType == Player1 && IsKeyDown(KEY_S)) {
        position.y += calcSpeed;
    }

    position.y = Clamp(position.y, 0, float(GetScreenHeight() - height));
}
