#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "SpriteSystem.h"
#include "Components.h"

SpriteSystem::SpriteSystem() {}

SpriteSystem::~SpriteSystem() {
    printf("..sprite system destroyed\n");
}

bool SpriteSystem::init(SDL_Renderer* renderer) {
    _renderer = renderer;
    // TODO: Write some fancy way of working this out.

    auto meeple = IMG_Load("dat/meeple.png");
    auto meepleTexture = SDL_CreateTextureFromSurface(_renderer, meeple);
    SDL_FreeSurface(meeple);
    if (meepleTexture == nullptr) {
        printf("Failed to initialise meeple texture during pre-render: %s\n", SDL_GetError());
        return false;
    }

    _spriteSheets.insert({"meeple", meepleTexture});

    return true;
}

void SpriteSystem::cleanup() {
    for (auto texture : _spriteSheets) {
        SDL_DestroyTexture(texture.second);
    }
    _spriteSheets.clear();
    printf("..shutdown sprite system\n");
}

bool SpriteSystem::render(Position * const position, Sprite * const sprite) {
    return true;
}
