#include "EntityManager.h"
#include "Components.h"

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

bool EntityManager::addPosition(unsigned int uuid, double x, double y, double z) {
    return false;
}

bool EntityManager::addSprite(unsigned int uuid, char * const spriteSheet,
                              int x, int y, int width, int height) {
    return false;
}
