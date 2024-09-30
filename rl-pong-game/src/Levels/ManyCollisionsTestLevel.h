#pragma once

#include "Core/EntityManager.h"
#include "Gameplay/Ball.h"
#include "Gameplay/Paddle.h"

class ManyCollisionsTestLevel {

private:
    //local to pong
    Paddle rect1 = Paddle({480, 120}, 20, 120, Player1);
    Paddle rect3 = Paddle({1200 - 460, 560}, 20, 120, Player2);

    // Ball ball = Ball({0.0, 0.0});
    static constexpr int NUM_BALLS = 1024;
    Ball* balls[NUM_BALLS];
    //level deserves an interface
public:
    ManyCollisionsTestLevel() {
        for (int i = 0; i < NUM_BALLS; ++i) {
            balls[i] = new Ball({0, 0});
            EntityManager::Instance().RegisterEntity(balls[i]);
        }

        EntityManager::Instance().RegisterEntity(&rect1);
        EntityManager::Instance().RegisterEntity(&rect3);
    }


    //
    // //interface functions
    // void LoadLevel() {}

    void UnloadLevel() {
        rect1.Destroy();
        rect3.Destroy();
        for (Ball* ball : balls) {
            ball->Destroy();
        }
    }

    void Start() {
        //create numballs number of balls
        for (Ball* ball : balls) {
            ball->Reset();
        }
    }

    static void Render() {};
};
