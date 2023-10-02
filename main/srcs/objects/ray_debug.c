#include "../../inc/minirt.h"

void    print_ray(t_ray *ray)
{
    printf(H_LINE);
    printf("ray origin: %f, %f, %f\n", ray->origin.x, ray->origin.y, ray->origin.z);
    printf("ray destination: %f, %f, %f\n", ray->destination.x, ray->destination.y, ray->destination.z);
    printf("ray direction: %f, %f, %f\n", ray->direction.x, ray->direction.y, ray->direction.z);
    printf("ray len: %f\n", ray->len);
    printf("ray raw: %f, %f, %f\n", ray->raw.x, ray->raw.y, ray->raw.z);

    printf(H_LINE);
}

void    print_ray_small(t_ray *ray)
{
    printf("[%.3f %.3f %.3f]\n", ray->raw.x, ray->raw.y, ray->raw.z);
}
