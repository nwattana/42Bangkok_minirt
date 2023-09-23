#include "../inc/minirt.h"

int collect_camera(char **splited_lint, t_prog *prog)
{
    t_camera	*camera;
    t_object    *object;

    prog->has_camera = 1;
    camera = malloc(sizeof(t_camera));
    if (camera == NULL)
        return (1);

    // position  direction fov
    collect_3d(splited_lint[1], &camera->position);
    collect_3d(splited_lint[2], &camera->normal);
    ft_strtod(splited_lint[3], &camera->fov);

    // add camera to object list
    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (0);
    object->type = CAMERA;
    object->object = camera;
    object->print = print_camera;
    ft_lstadd_back(&prog->obj, ft_lstnew(object));

	return (0);
}

/// @brief pases string 10, 10.0, -1 into 3d vector or 3d point
/// @return 
void    *collect_3d(char *str_vector, void *memory_in)
{
    char        **splited_vector;
    t_vec3d     *vector;

    vector = (t_vec3d *)memory_in;
    splited_vector = ft_split(str_vector, ',');
    if (vector == NULL)
        return (NULL);
    ft_strtod(splited_vector[0], &vector->x);
    ft_strtod(splited_vector[1], &vector->y);
    ft_strtod(splited_vector[2], &vector->z);        

    return (memory_in);
}