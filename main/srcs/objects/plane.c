#include "../../inc/minirt.h"
int     almost_equal(double a, double b);
double pl_cale_dist(t_ray *ray, t_plane *pl, int *hit, t_interparam *param);
void    print_plane(void    *pl)
{
    t_plane *plane;

    plane = (t_plane *)pl;
    printf(H_LINE);
    printf("Plane:\n");
    printf("  plane point:  %f, %f, %f\n", plane->point.x, plane->point.y, plane->point.z);
    printf("  plane normal: %f, %f, %f\n", plane->normal.x, plane->normal.y, plane->normal.z);
    printf("  plane color:  %d, %d, %d\n", plane->color.r, plane->color.g, plane->color.b);
    printf(H_LINE);
}

void    clean_plane(void *pl)
{
    t_plane *plane;

    plane = (t_plane *)pl;
    free(plane);
}


int     pl_test_intersection(void *object, t_interparam *param)
{
    t_vec3d     *ray;
    t_plane     *plane;
    t_object    *obj;
    double      dist;

    obj = (t_object *)object;
    plane = (t_plane *)obj->object;
    ray = &param->ray->direction;

    dist = pl_cale_dist(param->ray, plane, &param->f_ishit, param);
    if (dist > 0)
    {
        param->f_color = plane->color;
        param->f_dist = dist;
        param->f_point.x = param->ray->origin.x + dist * ray->x;
        param->f_point.y = param->ray->origin.y + dist * ray->y;
        param->f_point.z = param->ray->origin.z + dist * ray->z;
        param->f_normal = plane->normal;
        param->f_ishit = 1;
    }
    return (param->f_ishit);
}

// PROB
// plane [0,0,0] , normal = [0,0,1]
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

int almost_equal(double a, double b)
{
    return (fabs(a - b) < EPSILON);
}   