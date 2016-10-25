#pragma once

#include <SDL2/SDL.h>

#include "Window.h"

class RendererManager {
private:
    SDL_Renderer* _renderer;
    const char* _windowTitle = nullptr;

    SDL_Texture* _bgTexture = nullptr;
    SDL_Texture* _meepleTexture = nullptr;

public:
    RendererManager();
    ~RendererManager();

    bool init(Window& window);

    bool preRender();
    void render(int tick);

    void cleanUp();
};
