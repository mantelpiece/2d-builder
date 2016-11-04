#pragma once

#include <SDL2/SDL.h>
#include <memory>

#include "EventManager.h"
#include "Window.h"
#include "RendererManager.h"

// Forward declares
class EntityManager;

class Engine {
private:
    bool _initialised;
    std::unique_ptr<Window> _mainWindow;
    std::unique_ptr<EventManager> _eventManager;
    std::unique_ptr<RendererManager> _rendererManager;
    std::unique_ptr<EntityManager> _entityManager;

public:
    Engine();
    ~Engine();

    bool init();
    bool start();

private:
    bool mainLoop() const;
    void cleanup();
};
