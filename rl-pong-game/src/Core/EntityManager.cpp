#include "EntityManager.h"

#include <iostream>

void EntityManager::UpdateEntities(const float _deltaTime) {
    for (Entity* entity : entities) {
        std::cout << (entity->WillDestroy() ? " true" : " false") << "\n";
        std::cout << "active" << (entity->IsActive() ? " true" : " false") << "\n";
        if (entity != nullptr && entity->IsActive() && !entity->WillDestroy()) {
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
    std::cout << "Rendering Entities" << '\n';
    for (Entity* entity : entities) {
        if (entity->IsActive() && !entity->WillDestroy()) {
            entity->Render();
        }
    }
}

void EntityManager::RegisterEntity(Entity* _entity) {
    entities.push_back(_entity);
    _entity->Start();
}
