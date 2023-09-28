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
int     sp_test_intersection(void *object, t_interparam *p)
{
    t_vec3d v_hat;
    t_object *obj;
    t_sphere *sp;
    // compute the value of a, b and c
    double a;
    double b;
    double c;
    double test;

    obj = (t_object *)object;
    sp = (t_sphere *)obj->object;
    // apply_tfmat_to_ray(&p->ray, &obj->tfmat, &p->ray, BWD);

    vec3d_assign(&v_hat, &p->ray.direction);
    a = 1.0;
    b = 2.0 * vec3d_dot(&v_hat, &p->ray.origin);
    c = vec3d_dot(&p->ray.origin, &p->ray.origin) - 1.0;

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
            vec3d_scale(&p->intersection_point, t1, &v_hat);
        }
        else
        {
            vec3d_scale(&p->intersection_point, t2, &v_hat);
        }
        // intersection_point = intersection_point + ray origin
        vec3d_add(&p->intersection_point, &p->ray.origin);
        vec3d_normalize(&p->intersection_point);
        vec3d_assign(&p->local_normal, &p->intersection_point);
        ft_memcpy(&p->local_color, &sp->color, sizeof(t_color));

        return (1);
    }
    return (0);
}

//TODO function to test whether two floating are cloase to being equal