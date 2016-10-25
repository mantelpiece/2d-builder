#include "EntityManager.h"


EntityManager::EntityManager() {}

EntityManager::~EntityManager() {
    _positions.clear();
    _sprites.clear();
}

void EntityManager::deleteEntity(unsigned int uuid) {
    // TODO: Recycle uuid?
    // FIXME: Not all entities have all components.
    removePosition(uuid);
    removeSprite(uuid);
}

