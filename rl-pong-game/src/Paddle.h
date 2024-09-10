#pragma once
#include <iostream>

#include "raylib.h"
#include "Core/Entity.h"

class Paddle : public Entity {
private:
    Vector2 position = {0, 0};
    int width = 120;
    int height = 30;
    float speed = 10.0f;

public:
    void Start() override;

    void Update(float _deltaTime) override;

    void Render() override;

    Paddle(Vector2 _position):
        position(_position) {
        std::cout << "shouldDestroy: " << WillDestroy() << "\n";
    }

};
