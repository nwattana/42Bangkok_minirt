#ifndef SPHERE_H
# define SPHERE_H

# include "minirt.h"

typedef struct	s_sphere
{
    t_vec3d     center;
    double		radius;
    t_color     color;
}				t_sphere;

#endif