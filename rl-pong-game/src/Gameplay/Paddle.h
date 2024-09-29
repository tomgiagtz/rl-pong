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

protected:


private:
    float speed = 50.0f;
    ControlType controlType;

public:
    void Start() override;

    void Update(float _deltaTime) override;





    Paddle(const Vector2 _position = {0.f, 0.f}, int _width = 20, int _height = 120, ControlType _playerType = Player1):
        RectEntity(_position, _width, _height), controlType(_playerType) {
        shouldCollide = true;
    }

    Paddle(const Paddle& _other) :
        RectEntity(_other.position, _other.width, _other.height), speed(_other.speed), controlType(_other.controlType) {}

};
