#include "EntityManager.h"


EntityManager::EntityManager() {}

EntityManager::~EntityManager() {}

unsigned int EntityManager::createEntity() {
    return _nextId++;
};

