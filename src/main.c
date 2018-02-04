#include "wolf3d.h"

int     main(int argc, char** argv) {
    SDL_Window*     window;
    SDL_Renderer*   renderer;
    SDL_Texture*    texture;
    SDL_Event       event;
    char**          map;
    t_vec2D         pos;
    t_vec2D         dir;

    pos.x = 50;
    pos.y = 50;
    dir.x = 0;
    dir.y = 1;
    OpenCLInit();
    map = parse_map();
    if(map == NULL)
        printf("map failed\n");
    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
    printf("SDL is running.\n");

    window = SDL_CreateWindow("Première fenêtre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);

    unsigned int    color = 0x00000000;
    unsigned int    pixels[WINDOW_WIDTH * WINDOW_HEIGHT];
    for(int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++) {
        pixels[i] = color;
    }
    int j = 100;
    clock_t     previous_frame_timestamp = clock();
    while (1) {
        if ((clock() - previous_frame_timestamp) > SETTINGS_FRAME_DELAY) {
            for(int i = 0; i < WINDOW_WIDTH; i++) {
                    pixels[(i) + (j) * WINDOW_WIDTH] = color;
            }
            SDL_UpdateTexture(texture, NULL, &pixels, WINDOW_WIDTH * sizeof(unsigned int));
            while ( SDL_PollEvent(&event) ) {
                switch (event.type) {
                    case SDL_KEYDOWN:
                        switch( event.key.keysym.sym ){
                            case SDLK_z:
                                printf("z");
                                break;
                            case SDLK_s:
                                printf("s");
                                break;
                            case SDLK_q:
                                printf("q");
                                break;
                            case SDLK_d:
                                printf("d");
                                break;
                            case SDLK_ESCAPE:
                                printf("ok");
                                SDL_DestroyTexture(texture);
                                SDL_DestroyRenderer(renderer);
                                SDL_Quit();
                                return 0;
                                break;
                            default:
                                break;

                        }
                }
            }
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, NULL, NULL);
            SDL_RenderPresent(renderer);
            // if (color == 0xFF0000FF)
            color = 0xFFFFFFFF;
            // else
            //     color = 0xFF0000FF;
            previous_frame_timestamp = clock();
        }
    }
    return 0;
<<<<<<< HEAD
    (void)argc;
    (void)argv;
=======
>>>>>>> a8a8380d3783ef8ed8c438f9e821292b6e98e084
}
