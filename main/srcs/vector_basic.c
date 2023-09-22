#include "../inc/minirt.h"

/// @brief init value for vector a
/// @param a address of memory contain vector a
/// @param x vector a x
/// @param y vector a y
/// @param z vector a z
/// @return 0 if success, 1 if fail
int vector_init(t_vector *a, double x, double y, double z)
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
int vector_assign(t_vector *to, t_vector *from)
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
int vector_add(t_vector *a, t_vector *b)
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
t_vector* vector_plus(t_vector *res, t_vector *a, t_vector *b)
{
    if (a == NULL || b == NULL)
        return (res);
    res->x = a->x + b->x;
    res->y = a->y + b->y;
    res->z = a->z + b->z;

    return (res);
}

/// @brief minus vector a and vector b and assign to vector res (res = a - b)
/// @param res result vector
/// @param a 
/// @param b 
/// @return memory address contain result vector
t_vector *vector_minus(t_vector *res, t_vector *a, t_vector *b)
{
    if (a == NULL || b == NULL)
        return (res);
    res->x = a->x - b->x;
    res->y = a->y - b->y;
    res->z = a->z - b->z;

    return (res);
}

double  vector_len(t_vector *vector)
{
    return (sqrt(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z));
}


t_vector *vector_normalize(t_vector *res, t_vector *from)
{
    double length;

    if (from == NULL)
        return (res);
    length = vector_len(from);
    res->x = from->x / length;
    res->y = from->y / length;
    res->z = from->z / length;

    return (res);
}