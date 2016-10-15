#include <SDL2/SDL_image.h>

#include "RenderSystem.h"

RenderSystem::RenderSystem() : _renderer(nullptr) {
}

RenderSystem::~RenderSystem() {
    if (_renderer != nullptr) {
        cleanUp();
    }
}

bool RenderSystem::init(Window& window) {
    _windowTitle = window.getTitle();
    SDL_Window* sdlWindow = window.getSDL();
    _renderer = SDL_CreateRenderer(sdlWindow,
                                   -1,
                                   SDL_RENDERER_ACCELERATED);
    if (_renderer == nullptr) {
        printf("Failed to create SDL renderer: %s\n", SDL_GetError());
        return false;
    }

    printf("Created RenderSystem for window '%s'\n", _windowTitle);
    return true;
}

bool RenderSystem::preRender() {
    auto bg = SDL_LoadBMP("dat/helloWorld.bmp");
    _bgTexture = SDL_CreateTextureFromSurface(_renderer, bg);
    SDL_FreeSurface(bg);
    if (_bgTexture == nullptr) {
        printf("Failed to initialise bg texture during pre-render: %s\n", SDL_GetError());
    }

    auto meeple = IMG_Load("dat/meeple.png");
    _meepleTexture = SDL_CreateTextureFromSurface(_renderer, meeple);
    SDL_FreeSurface(meeple);
    if (_meepleTexture == nullptr) {
        printf("Failed to initialise meeple texture during pre-render: %s\n", SDL_GetError());
    }

    return true;
}

void RenderSystem::render(int tick) {
    // Clear back buffer.
    SDL_RenderClear(_renderer);

    // Render to back buffer.
    if (tick % 2 == 0) {
        SDL_SetRenderDrawColor(_renderer, 25, 25, 25, 255);
        SDL_RenderClear(_renderer);
    } else {
        SDL_RenderCopy(_renderer, _bgTexture, NULL, NULL);
    }

    SDL_Rect dstRect{100, 100, 48, 48};
    SDL_RenderCopy(_renderer, _meepleTexture, NULL, &dstRect);

    // Switch front and back buffers.
    SDL_RenderPresent(_renderer);
}

void RenderSystem::cleanUp() {
    SDL_DestroyTexture(_bgTexture);
    SDL_DestroyTexture(_meepleTexture);
    if (_renderer != nullptr) {
        SDL_DestroyRenderer(_renderer);
        _renderer = nullptr;
        printf("Render system for window '%s' destroyed\n", _windowTitle);
    }
}
