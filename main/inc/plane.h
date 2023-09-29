#ifndef PLANE_H
#define PLANE_H
#include "minirt.h"

typedef struct s_plane
{
    t_vec3d    point;
    t_vec3d    normal;
    t_color    color;
}   t_plane;

void    clean_plane(void *pl);
void    print_plane(void *pl);
int     pl_test_intersection(void *obj, t_interparam *param);
#endif