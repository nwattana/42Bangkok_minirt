#ifndef VECTOR_H
# define VECTOR_H
# include "minirt.h"

# define t_point3d t_vec3d

typedef struct s_vec3d
{
    double x;
    double y;
    double z;
}               t_vec3d;



int vec3d_init(t_vec3d *a, double x, double y, double z);
int vec3d_assign(t_vec3d *to, t_vec3d *from);
int vec3d_add(t_vec3d *to, t_vec3d *from);
int vec3d_plus(t_vec3d *res, t_vec3d *a, t_vec3d *b);
int vec3d_minus(t_vec3d *res, t_vec3d *a, t_vec3d *b);
int vec3d_cross(t_vec3d *res, t_vec3d *a, t_vec3d *b);
int vec3d_normalize(t_vec3d *a);
int vec3d_scale(t_vec3d *res, double scale, t_vec3d *a);
double vec3d_length(t_vec3d *a);
double vec3d_dot(t_vec3d *a, t_vec3d *b);
void    print_vec3d(t_vec3d *a);
void *collect_3d(char *str_vector, void *memory_in);
int vec3d_eq(t_vec3d *v1, t_vec3d *v2);
#endif