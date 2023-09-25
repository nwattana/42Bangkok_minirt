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

int point_light(t_light *light, t_list *current_obj, t_interparam *param, t_color *color, double *intensity)
{
    // light direction
    t_vec3d light_dir;
    // starting point
    t_point3d light_start;

    double norm_light_vec;
    double angle;

    vec3d_minus(&light_dir, &light->position, &param->intersection_point);
    vec3d_normalize(&light_dir);

    vec3d_assign(&light_start, &param->intersection_point);

    angle = acos(vec3d_dot(&param->local_normal, &light_dir));
    if (angle > 1.5708)
    {
        color_copy(color, &light->color);
        *intensity = 0.0;
        return (0);
    }
    else
    {
        color_copy(color, &light->color);
        *intensity = light->intensity * (1.0 - (angle / 1.5708));
        return (1);
    }
}