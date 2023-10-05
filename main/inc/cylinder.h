#ifndef CYLINDER_H
# define CYLINDER_H

# include "minirt.h"


// typedef struct	s_cylinder
// {
//     t_point3d   position;
//     t_vec3d     direction;
//     double      radius;
//     double		hight;
//     t_color     color;
// }	t_cylinder;

void   print_cylinder(void *cy);
void   clean_cylinder(void *cy);

#endif