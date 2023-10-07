#include "../../inc/minirt.h"

double  cy_cale_dist(t_ray *ray, t_cylinder *cy)
{
    double  a;
    double  b;
    double  c;
    t_vec3d cam2obj;
    double  dist;

    vec3d_minus(&cam2obj, &ray->origin, &cy->point);
    a = vec3d_dot(&ray->direction, &ray->direction) - pow(vec3d_dot(&ray->direction, &cy->normal), 2);
    b = 2.0 * (vec3d_dot(&cam2obj, &ray->direction) - vec3d_dot(&ray->direction, &cy->normal) * vec3d_dot(&cam2obj, &cy->normal));
    c = vec3d_dot(&cam2obj, &cam2obj) - pow(vec3d_dot(&cam2obj, &cy->normal), 2) - (cy->radi * cy->radi);

    return(solve_quadratic(a, b, c));
}

int cy_create_plane(t_plane *pl, t_cylinder *cy)
{
    t_vec3d     cale_temp;
    t_vec3d   temp;

    vec3d_scale(&cale_temp, cy->len / 2.0, &cy->normal);
    vec3d_plus(&temp, &cy->point, &cale_temp);
    ft_memcpy(&pl[0].color, &cy->color, sizeof(t_color));
    ft_memcpy(&pl[0].point, &temp, sizeof(t_vec3d));
    ft_memcpy(&pl[0].normal, &cy->normal, sizeof(t_vec3d));
    vec3d_scale(&cale_temp, -cy->len / 2.0, &cy->normal);
    vec3d_plus(&temp, &cy->point, &cale_temp);
    ft_memcpy(&pl[1].color, &cy->color, sizeof(t_color));
    ft_memcpy(&pl[1].point, &temp, sizeof(t_vec3d));
    vec3d_scale(&cale_temp, -1, &cy->normal);
    ft_memcpy(&pl[1].normal, &cale_temp, sizeof(t_vec3d));
    return (SUCCESS);
}

void print_inters_param(t_interparam *p)
{
    print_ray(p->ray, "ray: ");
    printf("inters_param: \n");
    print_vec3d(&p->f_point, "f_point: ");
    print_vec3d(&p->f_normal, "f_normal: ");
    printf("f_dist: %f\n", p->f_dist);
    print_color(&p->f_color);
    printf("f_ishit: %d\n", p->f_ishit);
}

int cy_intersection_point(t_vec3d *inters, t_ray *ray, double dist)
{
    t_vec3d *v3;

    vec3d_scale(inters, dist, &ray->direction);
    vec3d_plus(inters, &ray->origin, inters);
    if (vec3d_length(inters) == 0.0)
    {
        debug_message("cyhere intersection_point: inters is zero vector\n");
        return (ERROR);
    }
    return (SUCCESS);
}