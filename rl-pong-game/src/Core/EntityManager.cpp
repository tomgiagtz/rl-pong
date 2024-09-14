#include "EntityManager.h"


void EntityManager::UpdateEntities(const float _deltaTime) {
    for (Entity* entity : entities) {
        // std::cout << (entity->WillDestroy() ? " true" : " false") << "\n";
        // std::cout << "active" << (entity->IsActive() ? " true" : " false") << "\n";
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
    for (unsigned i = 0; i < numEntities; ++i) {
        Entity* entity = entities[i];
        if (entity == nullptr) {
            // std::cout << "BadOne" << '\n';
            throw std::runtime_error("Null Entity During Render");
        }
        if (entity->IsActive() && !entity->WillDestroy()) {
            entity->Render();
        }
    }
}


// void EntityManager::RegisterEntity(Entity* _entity) {
//     entities.push_back(_entity);
//     numEntities++;
//
//
//     _entity->Start();
// }
//
// }

void EntityManager::RegisterEntity(Entity* _entity, bool _manualActivate) {
    entities.push_back(_entity);
    numEntities++;
    if (!_manualActivate) {
        _entity->Start();
    }
}
