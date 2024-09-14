#pragma once
#include "EntityManager.h"
#include "Gameplay/Paddle.h"
#include "Gameplay/PongLevel.h"

class GameLoop {
private:
    bool isRunning = true;
    EntityManager* entityManager = &EntityManager::Instance();
    PongLevel pongLevel = PongLevel();

public:
    GameLoop();

    void Render();
    // void Init();
    void Update(float _deltaTime);
    void CheckExit();

    bool IsRunning() const {
        return isRunning;
    }

    void Destroy();
};
