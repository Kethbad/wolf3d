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

#define SETTINGS_FPS (100)
#define SETTINGS_FRAME_DELAY (CLOCKS_PER_SEC / SETTINGS_FPS)

#define OPENCL_DATA_SIZE (1024)

/*
*  MAIN.C
*/

/*
*  OPENCL_INIT.C
*/
int   OpenCLInit( void );
char *parse_map(void);


# endif
