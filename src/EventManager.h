#pragma once

#include <SDL2/SDL_events.h>

class EventManager {
public:
    bool _shouldQuit = false;
public:
    void pollEvents();
};
