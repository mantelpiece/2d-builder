#pragma once

#include <string>
#include <unordered_map>

// Forward declares.
struct SDL_Renderer;
struct SDL_Texture;
struct Position;
struct Sprite;

class SpriteSystem {
private:
    std::unordered_map<std::string, SDL_Texture*> _spriteSheets;

    SDL_Renderer* _renderer;

public:
    SpriteSystem();
    ~SpriteSystem();

    bool init(SDL_Renderer* renderer);
    void cleanup();

    bool render(Position * const, Sprite * const);
};
