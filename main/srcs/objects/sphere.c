#include "../../inc/minirt.h"
int     set_intersection_param(t_interparam *p, double t, t_vec3d *v_hat, t_ray *cal, t_object *obj);
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
    double t;
    t_ray cal;

    obj = (t_object *)object;
    sp = (t_sphere *)obj->object;
    // apply_tfmat_to_ray(&p->ray, &obj->tfmat, &p->ray, BWD);

    apply_tfmat_to_ray(&cal, &obj->tfmat, &p->ray, BWD);
    vec3d_assign(&v_hat, &cal.direction);

   // test vector we has intersection with sphere
    t = solve_quadratic(1, 2.0 * vec3d_dot(&v_hat, &cal.origin), vec3d_dot(&cal.origin, &cal.origin) - 1.0);
    if (t > 0.0)
    {
        // if t1 or t2 is negative, then we have an intersection behind the ray origin
        set_intersection_param(p, t, &v_hat, &cal, obj);

        return (1);
    }
    return (0);
}

int     set_intersection_param(t_interparam *p, double t, t_vec3d *v_hat, t_ray *cal, t_object *obj)
{
    t_sphere *sp;
    t_vec3d origin;
    t_vec3d temp;

    sp = (t_sphere *)obj->object;
    vec3d_init(&origin, 0 ,0, 0);

    // LOCAL INTERSECTION POINT
    vec3d_scale(&p->intersection_point, t, v_hat);
    // intersection_point = intersection_point + ray origin
    vec3d_add(&p->intersection_point, &(cal->origin));

    // Convert Local Intersection Point to World Intersection Point
    apply_tfmat_to_vec(&origin, &obj->tfmat, &origin, FWD);
    apply_tfmat_to_vec(&p->intersection_point, &obj->tfmat, &p->intersection_point, FWD);

    vec3d_minus(&p->local_normal, &p->intersection_point, &origin);
    vec3d_normalize(&p->local_normal);
    ft_memcpy(&p->local_color, &sp->color, sizeof(t_color));
}
