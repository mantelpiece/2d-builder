#include "engine/Engine.h"

int main(int argc, char **argv) {
    Engine engine{};

    if (!engine.init()) {
        printf("Failed to initialise engine\n");
    } else {
        engine.start();
    }
    return 0;
}
