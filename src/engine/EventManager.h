#pragma once

#include <SDL2/SDL_events.h>

class EventManager {
public:
    bool _shouldQuit = false;
public:

    ~EventManager() {
        printf("..event manager destroyed\n");
    }

    void pollEvents();
};
