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

// function to test intersction between ray and sphere
int     test_intersection(t_ray *ray, t_point3d *intersection_point, t_vec3d *local_normal, t_color *local_color)
{
    t_vec3d v_hat;
    // compute the value of a, b and c
    double a;
    double b;
    double c;
    double test;

    vec3d_assign(&v_hat, &ray->direction);
    a = 1.0;
    b = 2.0 * vec3d_dot(&v_hat, &ray->origin);
    c = vec3d_dot(&ray->origin, &ray->origin) - 1.0;

   // test vector we has intersection with sphere
    test = b * b - 4.0 * a * c;
    if (test > 0.0)
    {
        double testsqr = sqrt(test);
        double t1;
        double t2;
        t1 = (-b + testsqr) / (2.0 * a);
        t2 = (-b - testsqr) / (2.0 * a);

        // if t1 or t2 is negative, then we have an intersection behind the ray origin
        if (t1 < 0.0 || t2 < 0.0)
            return (0);
        if (t1 < t2)
        {
            vec3d_scale(intersection_point, t1, &v_hat);
        }
        if (t2 < t1)
        {
            vec3d_scale(intersection_point, t2, &v_hat);
        }
        return (1);
    }
    return (0);
}

//TODO function to test whether two floating are cloase to being equal

//