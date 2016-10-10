#include <SDL2/SDL.h>
#include "Window.h"

Window::Window() {
    printf("Default window cstor called\n");
}

Window::Window(const char *title) :
_title(title) {}

bool Window::create() {
    _window = SDL_CreateWindow(
        _title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );
    if (_window == nullptr) {
        printf("Failed to create SDL window: %s\n", SDL_GetError());
        return false;
    }
    printf("Created window: %s\n", _title);
    return true;
}

SDL_Renderer* Window::getRenderer() {
    if (_renderer == nullptr) {
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
        if (_renderer == nullptr) {
            printf("Failed to create SDL renderer: %s\n", SDL_GetError());
        }
    }
    return _renderer;
}

void Window::destroy() {
    if (_renderer != nullptr) {
        SDL_DestroyRenderer(_renderer);
        _renderer = nullptr;
        printf("Render for window '%s' destroyed\n", _title);
    }

    if (_window != nullptr) {
        SDL_DestroyWindow(_window);
        _window = nullptr;
        printf("Window destroyed: %s\n", _title);
    }
}

Window::~Window() {
    destroy();    
}
