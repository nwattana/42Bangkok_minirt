#ifndef MINIRT_H
# define MINIRT_H

#include "../lib/libft.h"
#include "../lib/get_next_line.h"
#include "../mlx/mlx.h"
#include "./minirt_struct.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct s_input
{
    t_list *obj;
    int    obj_count;
}            t_input;


// typedef struct s_minirt
// {
//     t_mlx   mlx;
//     t_scene scene;
// }               t_minirt;

#endif