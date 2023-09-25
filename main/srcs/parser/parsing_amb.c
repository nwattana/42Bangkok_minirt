#include "../../inc/minirt.h"

// FIXME : handle unneeded params
int     collect_ambient(char **split_line, t_prog *prog)
{
    t_ambient   *ambient;
    t_object    *object;

    ambient = malloc(sizeof(t_ambient));
    if (ambient == NULL)
        return (1);
    ft_strtod(split_line[1], &ambient->intensity);
    collect_color(split_line[2], &ambient->color);

    object = create_object_ambient(ambient);
    if (object == NULL)
        return (1);

    ft_lstadd_back(&prog->obj, ft_lstnew(object));
    return (0);
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