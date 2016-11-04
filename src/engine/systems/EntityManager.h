#pragma once

#include <map>
#include <memory>

#include "SpriteSystem.h"

// Forward declares.
struct SDL_Renderer;
struct SDL_Texture;

namespace component {
    struct Position;
    struct Sprite;
};

class EntityManager {
private:
    SDL_Renderer* _renderer;

    unsigned int _nextId = 0;

    std::map<unsigned int, component::Position*> _positions;
    std::map<unsigned int, component::Sprite*> _sprites;

    std::unique_ptr<SpriteSystem> _spriteSystem;

public:
    EntityManager();
    ~EntityManager();

    bool init(SDL_Renderer* renderer);
    void cleanup();

    unsigned int createEntity() { return _nextId++; };
    void deleteEntity(unsigned int uuid);

    bool addPosition(unsigned int uuid, double x, double y, double z);
    bool addSprite(unsigned int uuid, char * const spriteSheet, int x, int y, int width, int height);

    /**
     * Returns a const pointer to the Position component for the entity
     * with the given UUID.
     */
    component::Position * const getPosition(unsigned int uuid) const {
        return _positions.at(uuid);
    };

    /**
     * Returns a const pointer to the Sprite component for the entity
     * with the given UUID.
     */
    component::Sprite * const getSprite(unsigned int uuid) const {
        return _sprites.at(uuid);
    };

    void removePosition(unsigned int uuid) {
        _positions.erase(uuid);
    };

    void removeSprite(unsigned int uuid) {
        _sprites.erase(uuid);
    };
};
