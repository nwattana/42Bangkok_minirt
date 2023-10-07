#include "../../inc/minirt.h"

int almost_equal(double a, double b)
{
    return (fabs(a - b) < EPSILON);
}

double pl_cale_dist(t_ray *ray, t_plane *pl, int *hit, t_interparam *param)
{
    double dist;
    double dot;
    t_vec3d     inters_point;

    dist = -1;
    dot = vec3d_dot(&pl->normal, &ray->direction);
    if (almost_equal(dot, 0))
        return (0);
    vec3d_minus(&inters_point, &pl->point, &ray->origin);
    dist = vec3d_dot(&inters_point, &pl->normal) / dot;
    if (dist < 0)
        return (0);
    ft_memcpy(&param->f_normal, &pl->normal, sizeof(t_vec3d));
    if (dot > 0)
    {
        param->f_normal.x = -param->f_normal.x;
        param->f_normal.y = -param->f_normal.y;
        param->f_normal.z = -param->f_normal.z;
    }
    return (dist);
}


int sp_intersection_point(t_vec3d *inters, t_ray *ray, double dist)
{
    t_vec3d *v3;

    vec3d_scale(inters, dist, &ray->direction);
    vec3d_plus(inters, &ray->origin, inters);
    if (vec3d_length(inters) == 0.0)
    {
        debug_message("sphere intersection_point: inters is zero vector\n");
        return (ERROR);
    }
    return (SUCCESS);
}

double  sp_cale_dist(t_ray *ray, t_sphere *sp)
{
    double  a;
    double  b;
    double  c;
    t_vec3d cam2obj;
    double  dist;

    vec3d_minus(&cam2obj, &ray->origin, &sp->center);
    a = vec3d_dot(&ray->direction, &ray->direction);
    b = 2.0 * vec3d_dot(&cam2obj, &ray->direction);
    c = vec3d_dot(&cam2obj, &cam2obj) - (sp->radius * sp->radius);
    return(solve_quadratic(a, b, c));
}