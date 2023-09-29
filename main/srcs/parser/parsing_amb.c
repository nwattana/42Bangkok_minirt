#include "../../inc/minirt.h"

// FIXME : handle unneeded params
int     collect_ambient(char **split_line, t_prog *prog)
{
    double intensity;

    ft_strtod(split_line[1], &intensity);
    collect_color(split_line[2], &prog->ambient_color);
    color_scale(&prog->ambient_color, intensity, &prog->ambient_color);

    return (SUCCESS);
}

t_object *create_object_ambient(t_ambient *a)
{
    t_object    *object;

    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (NULL);
    object->type = AMBIENT;
    object->object = a;
    object->print = print_ambient;
    object->clean = clean_ambient;
    object->test_intersection = none_test_intersection;

    return (object);
}