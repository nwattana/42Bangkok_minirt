#include "../../inc/minirt.h"

int collect_cylinder(char **str, t_prog *prog)
{
    t_cylinder *cylinder;
    t_object *object;

    cylinder = malloc(sizeof(t_cylinder));
    if (cylinder == NULL)
        return (1);
    collect_3d(str[1], &cylinder->point);
    collect_3d(str[2], &cylinder->normal);
    ft_strtod(str[3], &cylinder->radius);
    ft_strtod(str[4], &cylinder->height);
    color_collect_string(str[5], &cylinder->color);

    object = create_object_cylinder(cylinder);
    if (object == NULL)
        return (1);
    prog->item_count++;
    object->id = prog->item_count;
    ft_lstadd_back(&prog->obj, ft_lstnew(object));
    return (0);
}

t_object *create_object_cylinder(t_cylinder *cylinder)
{
    t_object *object;

    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (0);
    object->type = CYLINDER;
    object->object = cylinder;
    object->print = print_cylinder;
    object->clean = clean_cylinder;
    // TODO update again when implementing Object itration
    object->test_intersection = none_test_intersection;

    return (object);
}

