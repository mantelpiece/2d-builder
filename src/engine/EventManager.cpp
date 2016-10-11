#include <SDL2/SDL_events.h>

#include "EventManager.h"

void EventManager::pollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            printf("Exit requested...\n");
            _shouldQuit = true;
        }
        if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                printf("Exit requested...\n");
                _shouldQuit = true;
            }
        }
    }
}
