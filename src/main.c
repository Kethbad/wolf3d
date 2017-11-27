#include "wolf3d.h"

void    runtime_init(t_runtime_env* env)
{
    env->exit_program = 0;
    env->previous_frame_timestamp = 0;
}

int     main( void ) {
    t_sdl_struct        sdl_struct;
    t_runtime_env       r_env;    

    runtime_init(&r_env);
    if (!w3d_sdl_init(&sdl_struct))
    {
        unsigned int    color = 0xFFFFFFFF;
        for(int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++) {
            sdl_struct.pixels[i] = color;
        }
        while (!r_env.exit_program) {
            if ((clock() - r_env.previous_frame_timestamp) > SETTINGS_FRAME_DELAY) {
                for(int i = 0; i < 100; i++) {
                    for(int j = 0; j < 100; j++) {
                        sdl_struct.pixels[(i + 100) + (j + 100) * WINDOW_WIDTH] = color;
                    }
                }
                while ( SDL_PollEvent(&sdl_struct.event) ) {
                    switch (sdl_struct.event.type) {
                        case SDL_QUIT:
                            r_env.exit_program = 1;
                            break;
                    }
                }
                w3d_sdl_display(&sdl_struct);       
                if (color == 0x0000FFFF)
                    color = 0xFFFF00FF;
                else
                    color = 0x0000FFFF;
                r_env.previous_frame_timestamp = clock();
            }
        }
    }

    OpenCLInit();
    return 0;
}
