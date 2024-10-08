﻿#pragma once
#include "EntityManager.h"
#include "../Levels/CollisionTestLevel.h"
#include "Gameplay/Paddle.h"
#include "../Levels/PongLevel.h"
#include "Levels/ManyCollisionsTestLevel.h"

class GameLoop {
private:
    bool isRunning = true;
    EntityManager* entityManager = &EntityManager::Instance();
    // PongLevel pongLevel = PongLevel();
    // CollisionTestLevel collisionTestLevel = CollisionTestLevel();
    ManyCollisionsTestLevel manyCollisionsTestLevel = ManyCollisionsTestLevel();
    std::vector<RectEntity*> colliderEntities;

public:
    GameLoop();

    void Render();
    static void CalcCollisions(std::vector<RectEntity*>* _collisionEntities);
    // void Init();
    void Update(float _deltaTime);
    void CheckExit();

    bool IsRunning() const {
        return isRunning;
    }

    void Destroy();
};
