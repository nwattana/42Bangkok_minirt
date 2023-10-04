#include "../../inc/minirt.h"

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

double sp_cale_dist(t_sphere *sphere, t_ray *ray)
{
    double a;
    double b;
    double c;
    double discriminant;
    t_vec3d oc;

    vec3d_minus(&oc, &ray->origin, &sphere->center);
    a = vec3d_dot(&ray->direction, &ray->direction);
    b = 2.0 * vec3d_dot(&oc, &ray->direction);
    c = vec3d_dot(&oc, &oc) - (sphere->radius * sphere->radius);
    discriminant = (b * b) - (4 * a * c);
    if (discriminant < 0)
        return (-1);
    else
        return ((-b - sqrt(discriminant)) / (2.0 * a));
}

// function to test intersction between ray and sphere
int     sp_test_intersection(void *object, t_interparam *p)
{
    t_ray *ray;
    t_sphere *sp;
    double dist;
    t_vec3d oc;

    sp = (t_sphere *)object;
    ray = p->ray;
    vec3d_minus(&oc, &ray->origin, &sp->center);

    double a;
    double b;
    double c;

    a = vec3d_dot(&ray->direction, &ray->direction);
    b = 2.0 * vec3d_dot(&oc, &ray->direction);
    c = vec3d_dot(&oc, &oc) - (sp->radius * sp->radius);

    double discriminant;

    dist = solve_quadratic(a, b, c);
    if (dist > 0.0)
    {
        return (1);
    }
    return (0);
}
