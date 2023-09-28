#include "../../inc/minirt.h"

/// @brief init value for vec3d a
/// @param a address of memory contain vec3d a
/// @param x vec3d  x
/// @param y vec3d  y
/// @param z vec3d  z
/// @return 0 if success, 1 if fail
int vec3d_init(t_vec3d *a, double x, double y, double z)
{
    if (a == NULL)
        return (1);
    a->x = x;
    a->y = y;
    a->z = z;

    return (0);
}

/// @brief assign vec3d `from` to vec3d `to`
/// @param to 
/// @param from
/// @return 0 if success, 1 if fail
int vec3d_assign(t_vec3d *to, t_vec3d *from)
{
    if (to == NULL || from == NULL)
        return (1);
    to->x = from->x;
    to->y = from->y;
    to->z = from->z;

    return (0);
}

/// @brief add vec3d b to vec3d a
/// @param to 
/// @param from 
/// @return 0 if success, 1 if fail
int vec3d_add(t_vec3d *a, t_vec3d *b)
{
    if (a == NULL || b == NULL)
        return (1);
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;

    return (0);
}

/// @brief plus vec3d a and vec3d b and assign to vec3d res
/// @param res result vec3d
/// @param a 
/// @param b 
/// @return memory address contain result vec3d
int vec3d_plus(t_vec3d *res, t_vec3d *a, t_vec3d *b)
{
    if (a == NULL || b == NULL)
        return (ERROR);
    res->x = a->x + b->x;
    res->y = a->y + b->y;
    res->z = a->z + b->z;

    return (SUCCESS);
}

/// @brief minus vec3d a and vec3d b and assign to vec3d res
/// @param res result vec3d
/// @param a 
/// @param b 
/// @return memory address contain result vec3d
int vec3d_minus(t_vec3d *res, t_vec3d *a, t_vec3d *b)
{
    if (a == NULL || b == NULL)
        return (ERROR);
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
    a->x /= length;
    a->y /= length;
    a->z /= length;

    return (SUCCESS);
}

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

void    print_vec3d(t_vec3d *a)
{
    printf("vec3d [ %.3f %.3f %.3f ]\n", a->x, a->y, a->z);
}