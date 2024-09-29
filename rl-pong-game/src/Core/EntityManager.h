#pragma once
#include <vector>

#include "Entity.h"
#include "RectEntity.h"

class EntityManager {
public:
    void UpdateEntities(float _deltaTime, std::vector<RectEntity*>* _colliderEntities);
    void RenderEntities();
    void RegisterEntity(Entity* _entity, bool _manualStart = false);


    static EntityManager& Instance() {
        static EntityManager* instance = new EntityManager();
        return *instance;
    }

private:
    EntityManager() = default;
    std::vector<Entity*> entities;

    std::vector<Entity*> collidingEntities;
    unsigned numEntities;
};
