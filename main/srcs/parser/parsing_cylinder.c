#include "../../inc/minirt.h"

int collect_cylinder(char **str, t_prog *prog)
{
    t_cylinder *cylinder;
    t_object *object;

    cylinder = malloc(sizeof(t_cylinder));
    if (cylinder == NULL)
        return (1);
    collect_3d(str[1], &cylinder->position);
    collect_3d(str[2], &cylinder->direction);
    collect_3d(str[3], &cylinder->radius);
    collect_3d(str[4], &cylinder->hight);
    color_collect_string(str[5], &cylinder->color);

    object = create_object_plane(cylinder);
    if (object == NULL)
        return (1);
    prog->item_count++;
    object->id = prog->item_count;
    ft_lstadd_back(&prog->obj, ft_lstnew(object));
    return (0);
}

t_object *create_object_cyliner(t_cylinder *cy)
{
    t_object *object;

    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (0);
    object->type = CYLINDER;
    object->object = cy;
    object->print = print_cylinder;
    object->clean = clean_cylinder;
    // object->test_intersection = pl_test_intersection;

    return (object);
}
