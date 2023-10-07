#include "../../inc/minirt.h"

int vec3d_init(t_vec3d *a, double x, double y, double z)
{
    if (a == NULL)
    {
        debug_message("vec3d_init: a is NULL");
        return (1);
    }
    a->x = x;
    a->y = y;
    a->z = z;

    return (0);
}

int vec3d_assign(t_vec3d *to, t_vec3d *from)
{
    if (to == NULL || from == NULL)
    {
        debug_message("vec3d_assign: to or from is NULL");
        return (1);
    }
    ft_memcpy(to, from, sizeof(t_vec3d));
    return (0);
}

int vec3d_add(t_vec3d *a, t_vec3d *b)
{
    if (a == NULL || b == NULL)
    {
        debug_message("vec3d_add: a or b is NULL");
        return (1);
    }
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;

    return (0);
}

int vec3d_plus(t_vec3d *res, t_vec3d *a, t_vec3d *b)
{
    if (a == NULL || b == NULL)
    {
        debug_message("vec3d_plus: a or b is NULL");
        return (ERROR);
    }
    res->x = a->x + b->x;
    res->y = a->y + b->y;
    res->z = a->z + b->z;

    return (SUCCESS);
}

