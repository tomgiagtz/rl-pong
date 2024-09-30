#pragma once

#include "Core/EntityManager.h"

class PongLevel {

private:
    //local to pong
    Paddle player1 = Paddle({0.f, 0.f}, 30, 120, Player1);
    Paddle player2 = Paddle({0.f, 0.f}, 30, 120, Player2);

    Ball ball = Ball(Vector2{GetScreenWidth() / 2.f, GetScreenHeight() / 2.f});
    //level deserves an interface
public:
    PongLevel() {
        EntityManager::Instance().RegisterEntity(&player1);
        EntityManager::Instance().RegisterEntity(&player2);
        EntityManager::Instance().RegisterEntity(&ball);
    }

    //
    // //interface functions
    // void LoadLevel() {}

    void UnloadLevel() {
        player1.Destroy();
        player2.Destroy();
        ball.Destroy();
    }

    void Start() {
        int xPos1 = 50;
        int xPos2 = GetScreenWidth() - 50 - player1.GetWidth();
        // 3/4 of the way across the screen
        int yPos = (GetScreenHeight() / 2) - (player1.GetHeight() / 2);

        player1.SetPosition({float(xPos1), float(yPos)});
        player2.SetPosition({float(xPos2), float(yPos)});
        ball.Reset();
    }

    static void Render() {
        int width = 20;
        DrawRectangle((GetScreenWidth() / 2) - width, 0, width, GetScreenHeight(), WHITE);
    }

};
