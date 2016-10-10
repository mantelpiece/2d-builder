#pragma once

#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    Window();
    Window(const char* title);
    ~Window();

    bool create();
    void destroy();

    SDL_Renderer* getRenderer();

private:
    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;
    const char* _title;
};
