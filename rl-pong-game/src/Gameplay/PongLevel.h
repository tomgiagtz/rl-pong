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
        int xPos1 = 50;
        int xPos2 = GetScreenWidth() - 50 - Paddle::WIDTH;
        // 3/4 of the way across the screen
        int yPos = (GetScreenHeight() / 2) - (Paddle::HEIGHT / 2);

        player1.SetPosition({float(xPos1), float(yPos)});
        player2.SetPosition({float(xPos2), float(yPos)});
    }

    void Render() {
        int width = 20;
        DrawRectangle((GetScreenWidth() / 2) - width, 0, width, GetScreenHeight(), WHITE);
    }

};
