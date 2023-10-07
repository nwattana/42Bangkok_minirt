#include "../../inc/minirt.h"

int vec3d_scale(t_vec3d *res, double scale, t_vec3d *a)
{
    if (res == NULL || a == NULL)
        return (ERROR);
    res->x = a->x * scale;
    res->y = a->y * scale;
    res->z = a->z * scale;

    return (SUCCESS);
}

double vec3d_dot(t_vec3d *a, t_vec3d *b)
{
    if (a == NULL || b == NULL)
    {
        printf("vec3d_dot: a or b is NULL\n");
        return (ERROR);
    }
    return (a->x * b->x + a->y * b->y + a->z * b->z);
}

void    print_vec3d(t_vec3d *a, char *message)
{
    printf("vec3d %s [ %.3f %.3f %.3f ]\n",message, a->x, a->y, a->z);
}

void    print_ray(t_ray *ray, char *mess)
{
    printf("ray %s:\n", mess);
    print_vec3d(&ray->origin, "origin");
    print_vec3d(&ray->direction, "direction");
}
