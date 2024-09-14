#include "GameLoop.h"

#include <iostream>

#include "raylib.h"

#define SCREENWIDTH 1280
#define SCREENHEIGHT 800


GameLoop::GameLoop() {
    SetTargetFPS(60);
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "rl-pong");

    pongLevel.Start();
}

void GameLoop::Render() {
    // drawing

    BeginDrawing();
    ClearBackground(GetColor(0x1b1b1b1b));
    DrawText("Hello", 200, 200, 20,WHITE);
    entityManager->RenderEntities();


    // static render of level
    pongLevel.Render();
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
