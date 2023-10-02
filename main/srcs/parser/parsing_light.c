#include "../../inc/minirt.h"


/// @return 1 if error, 0 if success
int collect_light(char **splited_line, t_prog *prog)
{
    t_light    *light;
    t_object    *object;

    prog->has_light = 1;
    light = malloc(sizeof(t_light));
    if (light == NULL)
        return (ERROR);
    
    // position intensity color
    collect_3d(splited_line[1], &light->position);
    ft_strtod(splited_line[2], &light->intensity);
    collect_color(splited_line[3], &light->color);

    // add light to object list
    prog->light = light;

    return (SUCCESS);
}

t_object *create_object_light(t_light *light)
{
    t_object *object;

    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (0);
    object->type = LIGHT;
    object->object = light;
    object->print = print_light;
    object->clean = clean_light;
    object->test_intersection = none_test_intersection;

    return (object);
}