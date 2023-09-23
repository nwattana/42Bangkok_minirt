#ifndef CAMERA_H
# define CAMERA_H
# include "minirt.h"

/// @brief  t_camera is a struct that contains the camera's origin, orientation, and fov.
/// @param  origin is a t_vec3dthat contains the camera's origin.
/// @param  orientation is a t_vec3dthat contains the camera's orientation.
/// @param  fov is an int that contains the camera's fov.
typedef struct s_camera
{
    t_vec3d     position;
    t_vec3d     normal;
    double         fov;
    int         is_init;
}	t_camera;

void    print_camera(void *cam);
void    clean_camera(void *cam);

#endif