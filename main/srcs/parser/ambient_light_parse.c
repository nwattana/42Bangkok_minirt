#include "../../inc/minirt.h"

// FIXME : handle unneeded params
int     collect_ambient(char **split_line, t_prog *prog)
{
    double intensity;

    if (prog->has_ambient == 1)
    {
        debug_message("Error\nOnly one ambient light is allowed\n");
        return (ERROR);
    }
    prog->has_ambient = 1;
    ft_strtod(split_line[1], &intensity);
    color_collect_string(split_line[2], &prog->ambient_color);
    color_scale(&prog->ambient_color, intensity, &prog->ambient_color);
    color_scale(&prog->ambient_intensity, 1.0/255.0, &prog->ambient_color);

    return (SUCCESS);
}

int collect_light(char **splited_line, t_prog *prog)
{
    t_light    *light;

    if (prog->has_light == 1)
    {
        debug_message("Error\nOnly one light is allowed\n");
        return (ERROR);
    }
    prog->has_light = 1;
    light = &prog->light;
    collect_3d(splited_line[1], &light->position);
    ft_strtod(splited_line[2], &light->intensity);
    color_collect_string(splited_line[3], &light->color);

    return (SUCCESS);
}