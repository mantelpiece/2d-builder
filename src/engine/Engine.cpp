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
    _mainWindow->destroy();
    printf("Shutting down Engine...\n");
    SDL_Quit();
    printf("Engine shutdown\n");
}

bool Engine::init() {
    printf("Initialising engine ... \n");
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        // Something failed, print error and exit.
        printf("Failed to initialise SDL: %s\n", SDL_GetError());
        _initialised = false;
    }
    _eventManager = std::unique_ptr<EventManager>(new EventManager{});
    if (_eventManager == nullptr) {
        printf("Failed to initialise EventManager\n");
        _initialised = false;
    }

    printf("Engine initialised\n");
    _initialised = true;
    return _initialised;
}

bool Engine::start() {
    _mainWindow = std::unique_ptr<Window>(new Window{"Main"});
    if (!_mainWindow->create()) {
        return false;
    }

    printf("Starting main loop...\n");
    return mainLoop();
}

bool Engine::mainLoop() {
    // TODO: Get the RenderSystem
    //       Call renderSystem.preRender();

    int i = 0;
    while (!_eventManager->_shouldQuit) {
        _eventManager->pollEvents();
        printf("Tick %d\n", ++i);

        // Call render function.
        // render(i);

        SDL_Delay(500);
    }

    printf("Main loop ended\n");
    return true;
}

