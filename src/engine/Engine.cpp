#include <memory>

#include "Engine.h"
#include "Window.h"
#include "EventManager.h"

Engine::Engine() : _initialised(false),
                   _mainWindow(nullptr),
                   _eventManager(nullptr) {
}

Engine::~Engine() {
    cleanup();
}

void Engine::cleanup() {
    printf("Shutting down Engine...\n");

    _renderSystem->cleanUp();
    _mainWindow->destroy();

    SDL_Quit();
    printf("Engine shutdown\n");
}

bool Engine::init() {
    auto success = true;
    printf("Initialising engine ... \n");
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        // Something failed, print error and exit.
        printf("Failed to initialise SDL: %s\n", SDL_GetError());
        success = false;
    }
    printf("..initialised SDL subsystem\n");
    _eventManager = std::unique_ptr<EventManager>(new EventManager{});
    if (_eventManager == nullptr) {
        printf("Failed to initialise event manager\n");
        success = false;
    }
    printf("..initialised event manager\n");

    _renderSystem = std::unique_ptr<RenderSystem>(new RenderSystem{});
    if (_renderSystem == nullptr) {
        printf("Failed to initialise render system\n");
        success = false;
    }
    printf("..initialised render system\n");

    if (success) {
        printf("Engine initialised\n");
        _initialised = true;
    }
    return success;
}

bool Engine::start() {
    _mainWindow = std::unique_ptr<Window>(new Window{"Main"});
    if (!_mainWindow->create()) {
        return false;
    }

    _renderSystem->init(*_mainWindow);

    printf("Starting main loop...\n");
    return mainLoop();
}

bool Engine::mainLoop() const {
    // TODO: Get the RenderSystem
    //       Call renderSystem.preRender();
    _renderSystem->preRender();

    int i = 0;
    while (!_eventManager->_shouldQuit) {
        _eventManager->pollEvents();

        // Call render function.
        _renderSystem->render(i++);

        SDL_Delay(500);
    }

    printf("Main loop ended\n");
    return true;
}

