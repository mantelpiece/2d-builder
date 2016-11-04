#include "EntityManager.h"
#include "Components.h"

#include "SpriteSystem.h"

EntityManager::EntityManager() {}

EntityManager::~EntityManager() {}

bool EntityManager::init(SDL_Renderer* renderer) {
    _renderer = renderer;

    _spriteSystem = std::make_unique<SpriteSystem>();
    _spriteSystem->init(renderer);

    return true;
}

void EntityManager::cleanup() {
    _positions.clear();
    _sprites.clear();

    _spriteSystem->cleanup();
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
