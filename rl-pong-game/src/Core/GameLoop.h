#pragma once
#include "EntityManager.h"
#include "Paddle.h"
#include "Gameplay/PongLevel.h"

class GameLoop {
private:
    bool isRunning = true;
    EntityManager* entityManager = &EntityManager::Instance();
    PongLevel pongLevel = PongLevel();
    Paddle player1 = Paddle({100.f, 50.f}, PLAYER1);
    Paddle player2 = Paddle({100.f, 150.f}, PLAYER2);

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
