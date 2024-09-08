#include "GameLoop.h"

#include <cstdio>

#include "raylib.h"

void GameLoop::Render() {
    // drawing
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Hello", 200, 200, 20,WHITE);
    EndDrawing();
}

void GameLoop::Init() {
    printf("howdy");
    entityManager = &EntityManager::Instance();
    SetTargetFPS(60);
    InitWindow(1280, 800, "Hello Raylib");
}

void GameLoop::Update(float _deltaTime = 0.0166666667f) {
    entityManager->UpdateEntities(_deltaTime);
    Render();
    CheckExit();
}

void GameLoop::CheckExit() {
    isRunning = !WindowShouldClose();
}
