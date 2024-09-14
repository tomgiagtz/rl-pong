#pragma once
#include <iostream>

#include "raylib.h"
#include "Core/Entity.h"

enum PlayerType {
    PLAYER1,
    PLAYER2,
    COM
};

class Paddle : public Entity {

public:
    static constexpr int HEIGHT = 120;
    static constexpr int WIDTH = 30;

private:
    Vector2 position = {0, 0};


    float speed = 50.0f;
    PlayerType playerType;

public:
    void Start() override;

    void Update(float _deltaTime) override;

    void Render() override;

    void SetPosition(Vector2 _position) {
        position = _position;
    }

    Paddle(Vector2 _position = {0.f, 0.f}, PlayerType _playerType = PLAYER1):
        position(_position), playerType(_playerType) {
        // std::cout << "shouldDestroy: " << WillDestroy() << "\n";
    }

    Paddle(const Paddle& other) :
        position(other.position), speed(other.speed), playerType(other.playerType) {}

};
