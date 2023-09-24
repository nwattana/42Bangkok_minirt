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
int    test_intersection(t_ray *ray, t_point3d *intersection_point, t_vec3d *local_normal, t_color *local_color);
#endif