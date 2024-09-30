#pragma once

#include "Core/EntityManager.h"
#include "Gameplay/Ball.h"
#include "Gameplay/Paddle.h"

class ManyCollisionsTestLevel {

private:
    //local to pong
    Paddle rect1 = Paddle({480, 120}, 20, 120, Player1);
    Paddle rect3 = Paddle({1200 - 460, 560}, 20, 120, Player2);

    Ball ball = Ball({0.0, 0.0});
    //level deserves an interface
public:
    ManyCollisionsTestLevel() {
        EntityManager::Instance().RegisterEntity(&rect1);
        EntityManager::Instance().RegisterEntity(&rect3);
        EntityManager::Instance().RegisterEntity(&ball);
    }

    //
    // //interface functions
    // void LoadLevel() {}

    void UnloadLevel() {
        rect1.Destroy();
        rect3.Destroy();
        ball.Destroy();
    }

    void Start() {
        ball.Reset();
    }

    static void Render() {};
};
