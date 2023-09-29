#include "../../inc/minirt.h"

int collect_plane(char **str, t_prog *prog)
{
    t_plane *plane;
    t_object *object;

    plane = malloc(sizeof(t_plane));
    if (plane == NULL)
        return (1);
    collect_3d(str[1], &plane->point);
    collect_3d(str[2], &plane->normal);
    collect_color(str[3], &plane->color);

    object = create_object_plane(plane);
    if (object == NULL)
        return (1);
    
    ft_lstadd_back(&prog->obj, ft_lstnew(object));
}

t_object *create_object_plane(t_plane *plane)
{
    t_object *object;

    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (0);
    object->type = PLANE;
    object->object = plane;
    object->print = print_plane;
    object->clean = clean_plane;
    object->test_intersection = pl_test_intersection;

    return (object);
}