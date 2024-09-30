#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Core/EntityManager.h"

class CollisionTestLevel {

private:
    //local to pong
    Paddle rect1 = Paddle({480, 120}, 120, 120, Player1);
    Paddle rect2 = Paddle({520, 340}, 120, 120, None);
    Paddle rect3 = Paddle({560, 560}, 120, 120, Player2);

    // Ball ball = Ball(Vector2{GetScreenWidth() / 2.f, GetScreenHeight() / 2.f});
    //level deserves an interface
public:
    CollisionTestLevel() {
        EntityManager::Instance().RegisterEntity(&rect1);
        EntityManager::Instance().RegisterEntity(&rect2);
        EntityManager::Instance().RegisterEntity(&rect3);
        // EntityManager::Instance().RegisterEntity(&ball);
    }

    //
    // //interface functions
    // void LoadLevel() {}

    void UnloadLevel() {
        rect1.Destroy();
        rect2.Destroy();
        rect3.Destroy();
        // ball.Destroy();
    }

    void Start() {}

    static void Render() {};
};
