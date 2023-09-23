#ifndef VECTOR_H
# define VECTOR_H
# include "minirt.h"

typedef struct s_vec3d
{
    double x;
    double y;
    double z;
}               t_vec3d;

// Namespacing
typedef struct s_point3d
{
    double x;
    double y;
    double z;
}               t_point3d;

int vector_init(t_vec3d *a, double x, double y, double z);
int vector_assign(t_vec3d *to, t_vec3d *from);
int vector_add(t_vec3d *a, t_vec3d *b);
t_vec3d* vector_plus(t_vec3d *res, t_vec3d *a, t_vec3d *b);
t_vec3d* vector_minus(t_vec3d *res, t_vec3d *a, t_vec3d *b);

void *collect_3d(char *str_vector, void *memory_in);

#endif