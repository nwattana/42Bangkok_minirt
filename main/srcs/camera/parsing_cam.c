#include "../../inc/minirt.h"

// FIXME : handle unneeded params
int collect_camera(char **splited_line, t_prog *prog)
{
    t_camera	*camera;
    t_object    *object;

    prog->has_camera = 1;
    camera = malloc(sizeof(t_camera));
    if (camera == NULL)
        return (1);

    // position  direction fov
    collect_3d(splited_line[1], &camera->position);
    collect_3d(splited_line[2], &camera->normal);
    ft_strtod(splited_line[3], &camera->fov);

    init_camera(camera);
    if (prog->camera != NULL)
    {
        debug_message("Only one camera is allowed");
        exit(1);
    }
    prog->camera = camera;
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
    ft_free_split(splited_vector);

    return (memory_in);
}

t_object *create_object_camera(t_camera *cam)
{
    t_object *object;

    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (NULL);
    object->type = CAMERA;
    object->object = cam;
    object->print = print_camera;
    object->clean = clean_camera;
    object->test_intersection = none_test_intersection;

    return (object);
}

void    clean_camera(void *cam)
{
    t_camera *camera;

    camera = (t_camera *)cam;
    free(camera);
}