#include "../../inc/minirt.h"

// FIXME : handle unneeded params
int collect_light(char **splited_line, t_prog *prog)
{
    t_light    *light;
    t_object    *object;

    prog->has_light = 1;
    light = malloc(sizeof(t_light));
    if (light == NULL)
        return (1);
    
    // position intensity color
    collect_3d(splited_line[1], &light->position);
    ft_strtod(splited_line[2], &light->intensity);
    collect_color(splited_line[3], &light->color);

    // add light to object list
    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (0);
    object->type = LIGHT;
    object->object = light;
    object->print = print_light;
    object->clean = clean_light;
    ft_lstadd_back(&prog->obj, ft_lstnew(object));
    return (0);
}