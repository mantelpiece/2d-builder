#include <SDL2/SDL.h>
#include "Window.h"

Window::Window() {
    printf("Default window cstor called\n");
}

Window::Window(const char *title) :
_title(title) {}

const char* Window::getTitle() {
    return _title;
}

SDL_Window* Window::getSDL() {
    return _window;
}

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

void Window::destroy() {
        if (_window != nullptr) {
        SDL_DestroyWindow(_window);
        _window = nullptr;
        printf("Window destroyed: %s\n", _title);
    }
}

Window::~Window() {
    destroy();    
}
