﻿#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Core/EntityManager.h"

class CollisionTestLevel {

private:
    //local to pong
    Paddle rect1 = Paddle({0.f, 0.f}, 120, 120, None);
    Paddle rect2 = Paddle({0.f, 0.f}, 120, 120, None);

    // Ball ball = Ball(Vector2{GetScreenWidth() / 2.f, GetScreenHeight() / 2.f});
    //level deserves an interface
public:
    CollisionTestLevel() {
        EntityManager::Instance().RegisterEntity(&rect1);
        EntityManager::Instance().RegisterEntity(&rect2);
        // EntityManager::Instance().RegisterEntity(&ball);
    }

    //
    // //interface functions
    // void LoadLevel() {}

    void UnloadLevel() {
        rect1.Destroy();
        rect2.Destroy();
        // ball.Destroy();
    }

    void Start() {}

    static void Render() {
        int width = 20;
        DrawRectangle((GetScreenWidth() / 2) - width, 0, width, GetScreenHeight(), WHITE);
    }

};
