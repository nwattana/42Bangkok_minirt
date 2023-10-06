#include "../../inc/minirt.h"
double  sp_cale_dist(t_ray *ray, t_sphere *sp);
int intersection_point(t_vec3d *inters, t_ray *ray, double dist);
int intersection_noraml(t_vec3d *normal, t_point3d *inters, t_point3d *center);

void   print_sphere(void *sph)
{
    t_sphere *sphere;

    sphere = (t_sphere *)sph;
    printf(H_LINE);
    printf("Sphere: %f\n", sphere->radius);
    printf("  sphere center: %f, %f, %f\n", sphere->center.x, sphere->center.y, sphere->center.z);
    printf("  sphere color:  %d, %d, %d\n", sphere->color.r, sphere->color.g, sphere->color.b);
    printf("  sphere radius: %f\n", sphere->radius);
    printf(H_LINE);
}

void   clean_sphere(void *sph)
{
    t_sphere *sphere;

    sphere = (t_sphere *)sph;
    free(sphere);
}

// function to test intersction between ray and sphere
int     sp_test_intersection(void *object, t_interparam *p)
{
    double dist;
    t_sphere *sp;
    t_object *obj;

    obj = (t_object *)object;
    sp = (t_sphere *)obj->object;
    dist = sp_cale_dist(p->ray, sp);
    if (dist > 0.0)
    {
        p->f_dist = dist;
        p->f_ishit = 1;
        p->f_ishit = 1;
        intersection_point(&p->f_point, p->ray, dist);
        intersection_noraml(&p->f_normal, &p->f_point, &sp->center);
        ft_memcpy(&p->f_color, &sp->color, sizeof(t_color));
    }
    return (p->f_ishit);
}

int intersection_noraml(t_vec3d *normal, t_point3d *inters, t_point3d *center)
{
    vec3d_minus(normal, inters, center);
    if(vec3d_normalize(normal))
    {
        debug_message("sphere intersection_normal: normal is zero vector\n");
        return (ERROR);
    }
    return (SUCCESS);
}

int intersection_point(t_vec3d *inters, t_ray *ray, double dist)
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