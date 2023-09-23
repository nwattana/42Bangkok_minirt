#ifndef LIGHT_H
# define LIGHT_H
# include "minirt.h"

typedef struct s_light
{
    t_point3d   position;
    t_color     color;
    double      intensity;
}               t_light;

void    print_light(void *light);
void    clean_light(void *light);

#endif