#include "wolf3d.h"

unsigned int    collision(t_vec3D vec, t_vec3D pos, char **map)
{
    int i;
    i = 0;

   // map = parse_map();
    unsigned int color = 0;
    // printf("/n hello: %f", vec.x);
// while 


    return(color);
}

t_vec3D     rotation_X(float angle, t_vec3D vec)
{
    t_vec3D vec_res;

    vec_res.x = vec.x;
    vec_res.y = vec.y * cos(angle) - vec.z * sin(angle);
    vec_res.z = vec.y * sin(angle) + vec.z * cos(angle);
    return(vec_res);
}

t_vec3D     rotation_Z(float angle, t_vec3D vec)
{
    t_vec3D vec_res;

    vec_res.x = vec.x * cos(angle) - vec.y * sin(angle);
    vec_res.y = vec.x * sin(angle) + vec.y * cos(angle);
    vec_res.z = vec.z;
    return(vec_res);
}


unsigned int    *main_loop(t_vec3D pos, t_vec3D direction, unsigned int *pixels, char **map) {

    int i = 0;
    int j = 0;
    t_vec3D vec; 
    vec.y = WINDOW_WIDTH / tan(FOV / 2);

    unsigned int    color = 0xFFFF0000;
    while( i < WINDOW_WIDTH) {
        j = 0;
        vec.x = i - (WINDOW_WIDTH / 2);
        while(j < WINDOW_HEIGHT)
        {
            vec.z = j - (WINDOW_HEIGHT / 2);
           // if(i > 200 || i < 1)
          //  if( j == 100)
         //       color = collision( vec, pos, map);
            pixels[(i) + (j) * WINDOW_WIDTH] = color;
            j++;
        }
        i++;
    }
    // int j = 100;
    // unsigned int    color = 0xFFFFFFFF;
    //         for(int i = 0; i < WINDOW_WIDTH; i++) {
    //                 pixels[(i) + (j) * WINDOW_WIDTH] = color;
    //         }

    return(pixels);

    
}