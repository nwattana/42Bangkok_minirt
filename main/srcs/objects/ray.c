#include "../../inc/minirt.h"

int create_ray(t_ray *ray, t_camera *cam, double u, double v)
{
    t_vec3d     destination;
    t_vec3d temp;

    vec3d_assign(&destination, &cam->lower_left_coner);

    // lower_left_corner + u*horizontal + v*vertical - origin
    vec3d_scale(&temp, u, &cam->horizontal);
    vec3d_add(&destination, &temp);
    vec3d_scale(&temp, v, &cam->vertical);
    vec3d_add(&destination, &temp); 
    vec3d_minus(&destination, &destination, &cam->origin);

    vec3d_assign(&ray->origin, &cam->origin);
    vec3d_assign(&ray->destination, &destination);
    vec3d_minus(&ray->raw, &destination, &cam->origin);

    static int  a= 0;
    // if (a < 10)
    // {
    //     print_ray(ray);
    //     a++;
    // }
    // else
    // {
    //     exit(1);
    // }

    ray->len = vec3d_length(&ray->raw);

    vec3d_assign(&ray->direction, &destination);
    vec3d_normalize(&ray->direction);
}