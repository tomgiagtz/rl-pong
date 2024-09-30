#pragma once
#include <iostream>

#include "raylib.h"
#include "Core/RectEntity.h"

enum ControlType {
    None,
    Player1,
    Player2,
    Com
};

class Paddle : public RectEntity {


private:
    float speed = 50.0f;
    ControlType controlType;

public:
    void Update(float _deltaTime) override;

    Paddle(const Vector2 _position, int _width = 20, int _height = 120, ControlType _playerType = Player1):
        RectEntity(_position, _width, _height), controlType(_playerType) {
        shouldCollide = true;
    }

    Paddle(const Paddle& _other) :
        RectEntity(_other.position, _other.width, _other.height), speed(_other.speed), controlType(_other.controlType) {}

};
