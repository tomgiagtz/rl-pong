#pragma once
#include <iostream>
#include <ostream>

class Entity {
public:
    virtual ~Entity() = default;

    virtual void Start() {
        isInitialized = true;
    }

    //pure virtual isn't properly overrided?
    virtual void Update(float _deltaTime) {}


    bool IsActive() const {
        return active;
    }

    void SetActive(bool _active) {
        active = _active;
    }

    bool WillDestroy() {
        return shouldDestroy;
    }

    virtual void Render() {}

    //marks entity for destruction at end of update loop in EntityManager
    void Destroy() {
        active = false;
        shouldDestroy = true;
    }

    bool IsInitialized() {
        return isInitialized;
    };

    void SetIsInitialized(bool _isInitialized) {
        isInitialized = _isInitialized;
    }

    //probably better to make this an interface
    virtual bool HasCollision() {
        return false;
    }

protected:
    bool active = true;
    bool shouldDestroy = false;
    bool isInitialized = false;
};
