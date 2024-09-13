#pragma once
#include "Paddle.h"
#include "Core/EntityManager.h"

class PongLevel {

private:
    //local to pong
    Paddle player1 = Paddle({0.f, 0.f}, PLAYER1);
    Paddle player2 = Paddle({0.f, 0.f}, PLAYER2);
    //level deserves an interface
public:
    PongLevel() {
        EntityManager::Instance().RegisterEntity(&player1);
        EntityManager::Instance().RegisterEntity(&player2);
    }

    //
    // //interface functions
    // void LoadLevel() {}

    void UnloadLevel() {
        player1.Destroy();
        player2.Destroy();
    }

    void Start() {
        int yPos1 = 50;
        int yPos2 = GetScreenHeight() - 50 - Paddle::HEIGHT;
        // 3/4 of the way across the screen
        int xPos = (GetScreenWidth() / 4 * 3) - (Paddle::WIDTH / 2);

        player1.SetPosition({float(xPos), float(yPos1)});
        player2.SetPosition({float(xPos), float(yPos2)});
    }



};
