#include <SDL2/SDL_image.h>

#include "RendererManager.h"

RendererManager::RendererManager() : _renderer(nullptr) {
}

RendererManager::~RendererManager() {
    if (_renderer != nullptr) {
        cleanUp();
    }
    printf("..renderer manager destroyed\n");
}

bool RendererManager::init(Window& window) {
    _windowTitle = window.getTitle();
    SDL_Window* sdlWindow = window.getSDL();
    _renderer = SDL_CreateRenderer(sdlWindow,
                                   -1,
                                   SDL_RENDERER_ACCELERATED);
    if (_renderer == nullptr) {
        printf("Failed to create SDL renderer: %s\n", SDL_GetError());
        return false;
    }

    printf("Created renderer manager for window '%s'\n", _windowTitle);
    return true;
}

void RendererManager::cleanUp() {
    SDL_DestroyTexture(_bgTexture);
    if (_renderer != nullptr) {
        SDL_DestroyRenderer(_renderer);
        _renderer = nullptr;
        printf("..shutdown renderer manager for window '%s'\n", _windowTitle);
    }
}

bool RendererManager::preRender() {
    auto bg = SDL_LoadBMP("dat/helloWorld.bmp");
    _bgTexture = SDL_CreateTextureFromSurface(_renderer, bg);
    SDL_FreeSurface(bg);
    if (_bgTexture == nullptr) {
        printf("Failed to initialise bg texture during pre-render: %s\n", SDL_GetError());
    }

    return true;
}

void RendererManager::render(int tick) {
    // Clear back buffer.
    SDL_RenderClear(_renderer);

    // Render to back buffer.
    if (tick % 2 == 0) {
        SDL_SetRenderDrawColor(_renderer, 25, 25, 25, 255);
        SDL_RenderClear(_renderer);
    } else {
        SDL_RenderCopy(_renderer, _bgTexture, NULL, NULL);
    }

    // Switch front and back buffers.
    SDL_RenderPresent(_renderer);
}
