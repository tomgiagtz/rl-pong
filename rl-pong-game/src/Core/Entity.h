#pragma once

class Entity {
public:
    virtual ~Entity() = default;
    virtual void Start() = 0;
    virtual void Update(float _deltaTime) = 0;


    bool IsActive() const {
        return active;
    }

    void SetActive(bool _active) {
        active = _active;
    }

    bool WillDestroy() {
        return shouldDestroy;
    }

    virtual void Render();

    //marks entity for destruction at end of update loop in EntityManager
    void Destroy() {
        active = false;
        shouldDestroy = true;
    }

private:
    bool active = true;
    bool shouldDestroy = false;
};
