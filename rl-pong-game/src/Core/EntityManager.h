#pragma once
#include <vector>

#include "Entity.h"

class EntityManager {
public:
    void UpdateEntities(float _deltaTime);
    void RenderEntities();
    void RegisterEntity(Entity* _entity);


    static EntityManager& Instance() {
        static EntityManager* instance = new EntityManager();
        return *instance;
    }

private:
    EntityManager() = default;
    std::vector<Entity*> entities;
};
