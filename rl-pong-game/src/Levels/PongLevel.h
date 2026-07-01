#pragma once

#include "Core/EntityManager.h"
#include "UI/Button.h"

class PongLevel {

private:
    //local to pong
    Paddle player1 = Paddle({0.f, 0.f}, 30, 120, Player1);
    Paddle player2 = Paddle({0.f, 0.f}, 30, 120, Player2);

    Ball ball = Ball(Vector2{GetScreenWidth() / 2.f, GetScreenHeight() / 2.f});
    Button startButton;
    //level deserves an interface
public:
    PongLevel() : startButton(Button(ButtonStyle(Vector2{100, 30},Vector2{(GetScreenWidth() / 2.f) - 50.f, GetScreenHeight() / 3.f}))) {
        EntityManager::Instance().RegisterEntity(&player1, true);
        EntityManager::Instance().RegisterEntity(&player2, true);
        EntityManager::Instance().RegisterEntity(&ball, true);
    }

    //
    // //interface functions
    void LoadLevel() {
        startButton.SetPosition({GetScreenWidth() / 2.f - 50.f, GetScreenHeight() / 3.f});
        EntityManager::Instance().RegisterEntity(&startButton);

        int xPos1 = 50;
        int xPos2 = GetScreenWidth() - 50 - player1.GetWidth();
        // 3/4 of the way across the screen
        int yPos = (GetScreenHeight() / 2) - (player1.GetHeight() / 2);
        player1.SetPosition({float(xPos1), float(yPos)});
        player2.SetPosition({float(xPos2), float(yPos)});
    }

    void UnloadLevel() {
        player1.Destroy();
        player2.Destroy();
        ball.Destroy();
    }

    void BeginPlay() {
        startButton.SetActive(false);
        player1.SetActive(true);
        player2.SetActive(true);
        ball.SetActive(true);
        ball.Reset();
        
    }

    void Update(float _deltaTime) {
        if (startButton.IsClickActionPending()) {
            BeginPlay();
            startButton.ClickActionHandled();
        }
    }

    static void Render() {
        int width = 20;
        DrawRectangle((GetScreenWidth() / 2) - (width *0.5f), 0, width, GetScreenHeight(), WHITE);
    }

};
