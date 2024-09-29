#pragma once
#include "EntityManager.h"
#include "Gameplay/CollisionTestLevel.h"
#include "Gameplay/Paddle.h"
#include "Gameplay/PongLevel.h"

class GameLoop {
private:
    bool isRunning = true;
    EntityManager* entityManager = &EntityManager::Instance();
    // PongLevel pongLevel = PongLevel();
    CollisionTestLevel collisionTestLevel = CollisionTestLevel();

    std::vector<RectEntity*> colliderEntities;

public:
    GameLoop();

    void Render();
    void CalcCollisions(std::vector<RectEntity*>* _collisionEntities);
    // void Init();
    void Update(float _deltaTime);
    void CheckExit();

    bool IsRunning() const {
        return isRunning;
    }

    void Destroy();
};
