#include "../../inc/minirt.h"

void    print_light(void *lg)
{
    t_light *light;

    light = (t_light *)lg;
    printf(H_LINE);
    printf("Light:\n");
    printf("  light position: %f, %f, %f\n", light->position.x, light->position.y, light->position.z);
    printf("  light intensity: %f\n", light->intensity);
    printf("  light color:   %d, %d, %d\n", light->color.r, light->color.g, light->color.b);
    printf(H_LINE);
}

void    clean_light(void *lg)
{
    t_light *light;

    light = (t_light *)lg;
    free(light);
}

int point_light(t_light *light, t_interparam *param)
{
    t_vec3d     light_dir;
    t_point3d   light_start;

    double angle;

    vec3d_minus(&light_dir, &light->position, &param->intersection_point);
    vec3d_normalize(&light_dir);
    // vec3d_normalize(&param->local_normal);
    // if (param->intersection_obj != NULL && param->intersection_obj->type == PLANE)
    // {
    //     print_vec3d(&param->intersection_point);
    // }
    vec3d_assign(&light_start, &param->intersection_point);
    angle = acos(vec3d_dot(&param->local_normal, &light_dir));
    if (angle > 1.5708)
    {
        param->intensity = 0;
        return (0);
    }
    param->intensity = light->intensity * (1.0 - (angle / 1.5708));
    // printf("angle: %f\n", angle);
    // DEBUG
    // if (param->intersection_obj->type == PLANE)
    // {
    //     printf("angle: %f\n", angle);
    //     printf("intensity: %f\n", param->intensity);
    // }

    return (1);
}