#include "EntityManager.h"

void EntityManager::UpdateEntities(const float _deltaTime) {
    for (Entity* entity : entities) {
        if (entity->IsActive()) {
            entity->Update(_deltaTime);
        }
    }

    for (unsigned int i = 0; i < entities.size(); i++) {
        if (entities[i]->WillDestroy()) {
            // Delete the entity and remove it from the vector
            delete entities[i];
            entities.erase(entities.begin() + i);

            // Adjust the counter as we've just removed an element
            i--;
        }
    }
}

void EntityManager::RenderEntities() {
    for (Entity* entity : entities) {
        if (entity->IsActive()) {
            entity->Render();
        }
    }
}

void EntityManager::RegisterEntity(Entity& _entity) {
    entities.push_back(&_entity);
    _entity.Start();
}
