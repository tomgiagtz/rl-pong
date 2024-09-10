#pragma once
#include "EntityManager.h"
#include "Paddle.h"
#include "Gameplay/PongLevel.h"

class GameLoop {
private:
    bool isRunning = true;
    EntityManager* entityManager;
    PongLevel pongLevel;

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
