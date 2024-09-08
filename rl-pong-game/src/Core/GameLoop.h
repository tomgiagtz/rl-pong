#pragma once
#include "EntityManager.h"

class GameLoop {
private:
    bool isRunning = true;
    EntityManager* entityManager;

public:
    GameLoop() {
        Init();
    }

    void Render();
    void Init();
    void Update(float _deltaTime);
    void CheckExit();

    bool IsRunning() const {
        return isRunning;
    }
};
