#include "GameLoop.h"

#include <iostream>

#include "Paddle.h"
#include "raylib.h"

#define SCREENWIDTH 1280
#define SCREENHEIGHT 800


GameLoop::GameLoop() {
    SetTargetFPS(60);
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "rl-pong");

    pongLevel.Start();

    // player1.SetPosition({50, 50});
    // player2.SetPosition({50, 150});
    // entityManager->RegisterEntity(&player1);
    // entityManager->RegisterEntity(&player2);
}

void GameLoop::Render() {
    // drawing
    BeginDrawing();
    ClearBackground(GetColor(0x1b1b1b1b));
    DrawText("Hello", 200, 200, 20,WHITE);
    entityManager->RenderEntities();
    EndDrawing();
}

void GameLoop::Update(float _deltaTime = 0.0166666667f) {
    entityManager->UpdateEntities(_deltaTime);
    CheckExit();
}

void GameLoop::CheckExit() {
    isRunning = !WindowShouldClose();
}

// game destroy before window close
void GameLoop::Destroy() {}
