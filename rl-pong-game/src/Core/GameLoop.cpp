#include "GameLoop.h"

#include <iostream>

#include "raylib.h"

#define SCREENWIDTH 1280
#define SCREENHEIGHT 800


GameLoop::GameLoop() {
    SetTargetFPS(60);
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "rl-pong");

    // pongLevel.Start();
    manyCollisionsTestLevel.Start();
}

void GameLoop::Render() {
    // drawing

    BeginDrawing();
    ClearBackground(GetColor(0x1b1b1b1b));
    entityManager->RenderEntities();
    DrawFPS(GetScreenWidth() - 95, 10);

    // static render of level
    // collisionTestLevel.Render();
    EndDrawing();
}

void GameLoop::CalcCollisions(std::vector<RectEntity*>* _collisionEntities) {
    // std::cout << "num colliders " << _collisionEntities->size() << std::endl;

    RectEntity* entity = nullptr;
    RectEntity* otherEntity = nullptr;
    for (int i = 0; i < _collisionEntities->size(); i++) {
        entity = _collisionEntities->at(i);
        // starting at i preventing double counts
        for (int j = i; j < _collisionEntities->size(); j++) {
            otherEntity = _collisionEntities->at(j);
            if (entity != otherEntity) {
                if (RectEntity::CheckRectOverlap(entity, otherEntity)) {
                    entity->OnCollisionBegin(otherEntity);
                    otherEntity->OnCollisionBegin(entity);
                } else {
                    entity->OnCollisionEnd(otherEntity);
                    otherEntity->OnCollisionEnd(entity);
                }
            }
        }
    }
}

void GameLoop::Update(float _deltaTime = 0.0166666667f) {
    CalcCollisions(&colliderEntities);
    colliderEntities.clear();
    entityManager->UpdateEntities(_deltaTime, &colliderEntities);
    CheckExit();
}

void GameLoop::CheckExit() {
    isRunning = !WindowShouldClose();
}

// game destroy before window close
void GameLoop::Destroy() {
    manyCollisionsTestLevel.UnloadLevel();
}
