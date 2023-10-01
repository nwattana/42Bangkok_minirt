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
    double dist;
    t_sphere *sphere;
    t_object *obj;

    obj = (t_object *)object;
    sphere = (t_sphere *)obj->object;
    dist = sp_cale_dist(sphere, &p->ray);


    if (dist > 0.0)
    {
        if (dist < p->min_dist)
        {
            printf("dist: %f\n", dist);
            exit(0);
            p->min_dist = dist;
            p->intersection_obj = obj;
            ft_memcpy(&p->intersection_point, &p->ray.destination, sizeof(t_point3d));
            vec3d_minus(&p->local_normal, &p->intersection_point, &sphere->center);
            vec3d_normalize(&p->local_normal);
            color_copy(&p->local_color,&sphere->color);
            p->color = get_rgb(&p->local_color);
            return (1);
        }
    }
    return (0);
}

int     set_intersection_param(t_interparam *p, double t, t_vec3d *v_hat, t_ray *cal, t_object *obj)
{
    return (0);
}
