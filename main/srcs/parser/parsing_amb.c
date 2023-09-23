#include "../../inc/minirt.h"

int     collect_ambient(char **split_line, t_prog *prog)
{
    t_ambient   *ambient;
    t_object    *object;

    ambient = malloc(sizeof(t_ambient));
    if (ambient == NULL)
        return (1);
    ft_strtod(split_line[1], &ambient->intensity);
    collect_color(split_line[2], &ambient->color);
    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (1);
    object->type = AMBIENT;
    object->object = ambient;
    object->print = print_ambient;
    object->clean = clean_ambient;
    ft_lstadd_back(&prog->obj, ft_lstnew(object));

    return (0);
}