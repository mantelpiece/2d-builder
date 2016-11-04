#pragma once

#include <memory>

struct SDL_Texture;

namespace component {
    struct Position {
        // TODO: Use magic?
        // const static unsigned int type = 1;
        double x;
        double y;
    };

    struct Sprite {
        // const static unsigned int type = 2;
        SDL_Texture* spriteSheet;
        int x;
        int y;
        int width;
        int height;
    };
}
