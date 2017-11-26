#include "wolf3d.h"

int     main(int argc, char** argv) {
    SDL_Window*     window;
    SDL_Renderer*   renderer;
    SDL_Texture*    texture;
    SDL_Event       event;

    OpenCLInit();

    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
    printf("SDL is running.\n");

    window = SDL_CreateWindow("Première fenêtre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);

    unsigned int    color = 0xFFFFFFFF;
    unsigned int    pixels[WINDOW_WIDTH * WINDOW_HEIGHT];
    for(int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++) {
        pixels[i] = color;
    }

    clock_t     previous_frame_timestamp = clock();
    while (1) {
        if ((clock() - previous_frame_timestamp) > SETTINGS_FRAME_DELAY) {
            printf("%lu\n", clock());
            for(int i = 0; i < 100; i++) {
                for(int j = 0; j < 100; j++) {
                    pixels[(i + 100) + (j + 100) * WINDOW_WIDTH] = color;
                }
            }
            SDL_UpdateTexture(texture, NULL, &pixels, WINDOW_WIDTH * sizeof(unsigned int));
            SDL_WaitEvent(&event);
            switch (event.type)
            {
                case SDL_QUIT:
                    SDL_DestroyTexture(texture);
                    SDL_DestroyRenderer(renderer);
                    SDL_Quit();
                    return 0;
            }
            SDL_PumpEvents();
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, NULL, NULL);
            SDL_RenderPresent(renderer);
            if (color == 0xFF0000FF)
                color = 0x000000FF;
            else
                color = 0xFF0000FF;
            previous_frame_timestamp = clock();
        }
    }

    return 0;
    (void)argc;
    (void)argv;
}