#include "wolf3d.h"

int     w3d_sdl_init(t_sdl_struct* sdl_struct)
{
    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
    printf("SDL is running.\n");

    sdl_struct->window = SDL_CreateWindow("Première fenêtre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    sdl_struct->renderer = SDL_CreateRenderer(sdl_struct->window, -1, SDL_RENDERER_PRESENTVSYNC);
    sdl_struct->texture = SDL_CreateTexture(sdl_struct->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
    return 0;
}

void    w3d_sdl_cleanup(t_sdl_struct* sdl_struct)
{
    SDL_DestroyTexture(sdl_struct->texture);
    SDL_DestroyRenderer(sdl_struct->renderer);
    SDL_Quit();
}

void    w3d_sdl_display(t_sdl_struct* sdl_struct)
{
    SDL_UpdateTexture(sdl_struct->texture, NULL, &sdl_struct->pixels, WINDOW_WIDTH * sizeof(unsigned int));
    SDL_RenderClear(sdl_struct->renderer);
    SDL_RenderCopy(sdl_struct->renderer, sdl_struct->texture, NULL, NULL);
    SDL_RenderPresent(sdl_struct->renderer);
}
