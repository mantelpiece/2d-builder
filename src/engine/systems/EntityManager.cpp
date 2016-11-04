#include "EntityManager.h"
#include "Components.h"

#include "SpriteSystem.h"

EntityManager::EntityManager() {}

EntityManager::~EntityManager() {
    printf("..entity manager detroyed\n");
}

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
    _spriteSystem = nullptr;
    printf("..shutdown entity manager\n");
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
    // auto component = _spriteSystem->create(spriteSheet, x, y, width, height);
    // _sprites.insert({uuid, component});
    return false;
}
