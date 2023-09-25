#ifndef SPHERE_H
# define SPHERE_H

# include "minirt.h"

typedef struct	s_sphere
{
    t_point3d   center;
    double		radius;
    t_color     color;
}				t_sphere;

void   print_sphere(void *sphere);
void   clean_sphere(void *sphere);
int    sp_test_intersection(void *object, t_interparam *p);

#endif