#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Window.h"

class RenderSystem {
private:
    SDL_Renderer* _renderer;
    const char* _windowTitle = nullptr;

    SDL_Texture* _bgTexture = nullptr;
    SDL_Texture* _meepleTexture = nullptr;

public:
    RenderSystem();
    ~RenderSystem();

    bool init(Window& window);

    bool preRender();
    void render(int tick);

    void cleanUp();
};
