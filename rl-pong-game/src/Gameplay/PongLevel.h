#pragma once
#include "Paddle.h"
#include "Core/EntityManager.h"

class PongLevel {

private:
    //local to pong
    Paddle paddle;
    //level deserves an interface
public:
    PongLevel():
        paddle(Paddle(Vector2{0.0f, 0.0f})) {
        EntityManager::Instance().RegisterEntity(&paddle);
    }

    //
    // //interface functions
    // void LoadLevel() {}

    void UnloadLevel() {
        paddle.Destroy();
    }






};
