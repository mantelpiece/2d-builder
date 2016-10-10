#include <memory>

#include "Engine.h"
#include "Window.h"

Engine::Engine() : _initialised(false),
                   _mainWindow(nullptr) {
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

void render(SDL_Renderer* renderer, int tick, SDL_Texture* bg);

bool Engine::mainLoop() {
    SDL_Renderer* renderer = _mainWindow->getRenderer();

    auto bg = SDL_LoadBMP("helloWorld.bmp");
    auto bgTexture = SDL_CreateTextureFromSurface(renderer, bg);
    SDL_FreeSurface(bg);

    int i = 0;
    bool running = true;
    while (running) {
        SDL_Delay(100);
        printf("Tick %d\n", ++i);

        render(renderer, i, bgTexture);

        if (i > 10) {
            running = false;
        }
    }

    SDL_DestroyTexture(bgTexture);

    printf("Main loop ended\n");
    return true;
}

void render(SDL_Renderer* renderer, int tick, SDL_Texture* bg) {
    SDL_RenderClear(renderer);
    if (tick % 2 == 0) {
        SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
        SDL_RenderClear(renderer);
    } else {
        SDL_RenderCopy(renderer, bg, NULL, NULL);
    }
    SDL_RenderPresent(renderer);
}
