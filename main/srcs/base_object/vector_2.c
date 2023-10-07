#include "../../inc/minirt.h"

int vec3d_minus(t_vec3d *res, t_vec3d *a, t_vec3d *b)
{
    if (a == NULL || b == NULL || res == NULL)
    {
        debug_message("vec3d_minus: a or b is NULL");
        return (ERROR);
    }
    res->x = a->x - b->x;
    res->y = a->y - b->y;
    res->z = a->z - b->z;

    return (SUCCESS);
}

int vec3d_cross(t_vec3d *res, t_vec3d *a, t_vec3d *b)
{
    if (res == NULL)
        return (ERROR);
    res->x = a->y * b->z - a->z * b->y;
    res->y = a->z * b->x - a->x * b->z;
    res->z = a->x * b->y - a->y * b->x;
    
    return (SUCCESS);
}

double vec3d_length(t_vec3d *a)
{
    if (a == NULL)
        return (ERROR);
    return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}

int vec3d_normalize(t_vec3d *a)
{
    double length;

    if (a == NULL)
        return (ERROR);
    length = vec3d_length(a);
    if (length == 0)
    {
        debug_message("vec3d_normalize: length is 0");
        return (ERROR);
    }
    a->x /= length;
    a->y /= length;
    a->z /= length;

    return (SUCCESS);
}
