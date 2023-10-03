#ifndef LIGHT_H
# define LIGHT_H
# include "minirt.h"

typedef struct s_light
{
    int         count;
    t_point3d   position;
    t_color     color;
    double      intensity;
}               t_light;

void    print_light(void *light);
void    clean_light(void *light);
int     point_light(t_light *light, t_interparam *param, t_prog *prog);

#endif