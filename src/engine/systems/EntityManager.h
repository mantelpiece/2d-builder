#pragma once

#include <map>
#include <memory>

// Convenience define.
#define s_ptr(type) std::shared_ptr<type>
#define w_ptr(type) std::weak_ptr<type>

// Forward declares.
struct SDL_Texture;

namespace component {
    struct Position {
        const static unsigned int type = 1;
        double x;
        double y;
    };

    struct Sprite {
        const static unsigned int type = 2;
        std::shared_ptr<SDL_Texture> spriteSheet;
        int x;
        int y;
        int width;
        int height;
    };
}

class EntityManager {
private:
    unsigned int _nextId = 0;

    std::map<unsigned int, s_ptr(component::Position)> _positions;
    std::map<unsigned int, s_ptr(component::Sprite)> _sprites;

public:
    EntityManager();
    ~EntityManager();

    unsigned int createEntity();
    void deleteEntity(unsigned int uuid);
    
    w_ptr(component::Position) getPosition(unsigned int uuid);
    w_ptr(component::Sprite) getSprite(unsigned int uuid);

    void removePosition(unsigned int uuid);
    void removeSprite(unsigned int uuid);
};
