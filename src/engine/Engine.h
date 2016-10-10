#pragma once

#include <SDL2/SDL.h>
#include <memory>

#include "EventManager.h"
#include "Window.h"

class Engine {
private:
    bool _initialised;
    std::unique_ptr<Window> _mainWindow;
    std::unique_ptr<EventManager> _eventManager;

public:
    Engine();
    ~Engine();

    bool init();
    bool start();

private:
    bool mainLoop();
    void cleanup();
};
