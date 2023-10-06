#include "../../inc/minirt.h"

int     collect_sphere(char **splited_str, t_prog *prog)
{
    t_sphere    *sphere;
    t_object    *object;

    sphere = malloc(sizeof(t_sphere));
    if (sphere == NULL)
        return (1);
    
    collect_3d(splited_str[1], &sphere->center);
    ft_strtod(splited_str[2], &sphere->radius);
    color_collect_string(splited_str[3], &sphere->color);

    object = create_object_sphere(sphere);
    if (object == NULL)
        return (1);
    prog->item_count++;
    object->id = prog->item_count;
    ft_lstadd_back(&prog->obj, ft_lstnew(object));
    return (0);
}

t_object    *create_object_sphere(t_sphere *sp)
{
    t_object *object;

    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (0);
    object->type = SPHERE;
    object->object = sp;
    object->print = print_sphere;
    object->clean = clean_sphere;
    object->test_intersection = sp_test_intersection;

    return (object);
}
