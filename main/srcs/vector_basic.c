#include "../inc/minirt.h"

/// @brief init value for vector a
/// @param a address of memory contain vector a
/// @param x vector a x
/// @param y vector a y
/// @param z vector a z
/// @return 0 if success, 1 if fail
int vector_init(t_vec3d *a, double x, double y, double z)
{
    if (a == NULL)
        return (1);
    a->x = x;
    a->y = y;
    a->z = z;

    return (0);
}

/// @brief assign vector `from` to vector `to`
/// @param to 
/// @param from
/// @return 0 if success, 1 if fail
int vector_assign(t_vec3d *to, t_vec3d *from)
{
    if (to == NULL || from == NULL)
        return (1);
    to->x = from->x;
    to->y = from->y;
    to->z = from->z;

    return (0);
}

/// @brief add vector b to vector a
/// @param to 
/// @param from 
/// @return 0 if success, 1 if fail
int vector_add(t_vec3d *a, t_vec3d *b)
{
    if (a == NULL || b == NULL)
        return (1);
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;

    return (0);
}

/// @brief plus vector a and vector b and assign to vector res
/// @param res result vector
/// @param a 
/// @param b 
/// @return memory address contain result vector
t_vec3d* vector_plus(t_vec3d *res, t_vec3d *a, t_vec3d *b)
{
    if (a == NULL || b == NULL)
        return (res);
    res->x = a->x + b->x;
    res->y = a->y + b->y;
    res->z = a->z + b->z;

    return (res);
}

/// @brief minus vector a and vector b and assign to vector res
/// @param res result vector
/// @param a 
/// @param b 
/// @return memory address contain result vector
t_vec3d *vector_minus(t_vec3d *res, t_vec3d *a, t_vec3d *b)
{
    if (a == NULL || b == NULL)
        return (res);
    res->x = a->x - b->x;
    res->y = a->y - b->y;
    res->z = a->z - b->z;

    return (res);
}
