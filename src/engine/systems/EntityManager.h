#pragma once

#include <map>
#include <memory>

#include "Components.h"

// Convenience define.
#define s_ptr(type) std::shared_ptr<type>

// Forward declares.
struct SDL_Texture;

class EntityManager {
private:
    unsigned int _nextId = 0;

    std::map<unsigned int, s_ptr(component::Position)> _positions;
    std::map<unsigned int, s_ptr(component::Sprite)> _sprites;

public:
    EntityManager();
    ~EntityManager();

    unsigned int createEntity() { return _nextId++; };
    void deleteEntity(unsigned int uuid);

    bool addPosition(unsigned int uuid);
    bool addSprite(unsigned int uuid);

    /**
     * Returns a const pointer to the Position component for the entity
     * with the given UUID.
     */
    component::Position * const getPosition(unsigned int uuid) const {
        return _positions.at(uuid).get();
    };

    /**
     * Returns a const pointer to the Sprite component for the entity
     * with the given UUID.
     */
    component::Sprite * const getSprite(unsigned int uuid) const {
        return _sprites.at(uuid).get();
    };

    void removePosition(unsigned int uuid) {
        _positions.erase(uuid);
    };

    void removeSprite(unsigned int uuid) {
        _sprites.erase(uuid);
    };
};
