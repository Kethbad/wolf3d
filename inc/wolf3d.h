#ifndef __WOLF_3D__
# define __WOLF_3D__

#include <OpenCL/opencl.h>
#include "SDL.h"

#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/*
*  PROJECT SETINGS
*/
#define WINDOW_WIDTH (800)
#define WINDOW_HEIGHT (600)
#define FOV (80)

#define SETTINGS_FPS (100)
#define SETTINGS_FRAME_DELAY (CLOCKS_PER_SEC / SETTINGS_FPS)

#define OPENCL_DATA_SIZE (1024)


typedef struct      s_sdl_struct {
    SDL_Window*     window;
    SDL_Renderer*   renderer;
    SDL_Texture*    texture;
    SDL_Event       event;

    unsigned int    pixels[WINDOW_WIDTH * WINDOW_HEIGHT];
}                   t_sdl_struct;

typedef struct      s_runtime_env {
    char            exit_program;
    clock_t         previous_frame_timestamp;
}                   t_runtime_env;

/* 
*  MAIN.C
*/
typedef struct          s_vec3D {
    float               x;
    float               y;
    float               z;
}                       t_vec3D;

/*
*  OPENCL_INIT.C
*/
int   OpenCLInit( void );
char **parse_map(void);

/*
*  W3D_SDL_INIT.C
*/
int     w3d_sdl_init(t_sdl_struct* sdl_struct);
void    w3d_sdl_cleanup(t_sdl_struct* sdl_struct);
void    w3d_sdl_display(t_sdl_struct* sdl_struct);

/*
*  image_calculation.C
*/
unsigned int    *main_loop(t_vec3D pos, t_vec3D direction, unsigned int *pixels, char **map);
# endif
