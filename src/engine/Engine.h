#pragma once

#include <SDL2/SDL.h>
#include <memory>

#include "EventManager.h"
#include "Window.h"
#include "RenderSystem.h"

class Engine {
private:
    bool _initialised;
    std::unique_ptr<Window> _mainWindow;
    std::unique_ptr<EventManager> _eventManager;
    std::unique_ptr<RenderSystem> _renderSystem;

public:
    Engine();
    ~Engine();

    bool init();
    bool start();

private:
    bool mainLoop() const;
    void cleanup();
};
