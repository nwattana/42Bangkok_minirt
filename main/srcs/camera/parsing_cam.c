#include "../../inc/minirt.h"

// FIXME : handle unneeded params
int collect_camera(char **splited_line, t_prog *prog)
{
    t_camera	*camera;

    if (prog->has_camera == 1)
    {
        debug_message("Only one camera is allowed");
        exit(1);
    }
    prog->has_camera = 1;
    camera = &prog->camera;
    // position  direction fov
    collect_3d(splited_line[1], &camera->position);
    collect_3d(splited_line[2], &camera->normal);
    ft_strtod(splited_line[3], &camera->fov);

    init_camera(camera);
	return (0);
}

/// @brief pases string 10,10.0,-1 into 3d vector or 3d point
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