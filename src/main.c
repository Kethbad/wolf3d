#include "wolf3d.h"

int     main(int argc, char** argv) {
    SDL_Window*     screen;

    OpenCLInit();

    if (!SDL_Init(SDL_INIT_EVERYTHING)) {
        printf("SDL is running.\n");
        SDL_CreateWindow(
            "mon super test",
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            640, 480,
            SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL
        );
        SDL_Quit();
    }

    return 0;
    (void)argc;
    (void)argv;
}