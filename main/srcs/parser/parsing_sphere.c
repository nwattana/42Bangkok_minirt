#include "../../inc/minirt.h"

int     collect_sphere(char **splited_str, t_prog *prog)
{
    t_sphere    *sphere;
    t_object    *object;

    sphere = malloc(sizeof(t_sphere));
    if (sphere == NULL)
        return (1);
    
    // center radius color
    collect_3d(splited_str[1], &sphere->center);
    ft_strtod(splited_str[2], &sphere->radius);
    collect_color(splited_str[3], &sphere->color);

    // add sphere to object list
    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (0);
    object->type = SPHERE;
    object->object = sphere;
    object->print = print_sphere;
    object->clean = clean_sphere;
    ft_lstadd_back(&prog->obj, ft_lstnew(object));


    return (0);
}