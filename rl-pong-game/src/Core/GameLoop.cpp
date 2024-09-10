#include "GameLoop.h"

#include <iostream>

#include "Paddle.h"
#include "raylib.h"


GameLoop::GameLoop() {
    SetTargetFPS(60);
    InitWindow(1280, 800, "rl-pong");

    pongLevel = PongLevel();
    entityManager = &EntityManager::Instance();
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
