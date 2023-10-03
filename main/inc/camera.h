#ifndef CAMERA_H
# define CAMERA_H
# include "minirt.h"

# define CAMERA_LEN 1.0
# define ASPECT_RATIO (16.0 / 9.0)
# define HORIZONTAL_SIZE 1


/// @brief  t_camera is a struct that contains the camera's origin, orientation, and fov.
/// @param  position is a point that contains the camera's origin.
/// @param  normal is a t_vec3d that contains the camera's orientation.
/// @param  fov is an int that contains the camera's fov.
typedef struct s_camera
{
    int         count;

    t_point3d   position;
    // m_alignment vertor
    t_vec3d     normal;
    double         fov;
    double         fov_rad;
    int         is_init;
    t_vec3d     cam_up;
    t_vec3d     projection_screen_u;
    t_vec3d     projection_screen_v;
    double      cam_len;
    double      screen_width;
    double      screen_height;

    double      horizontal;
    t_vec3d     screen_center;
    double      aspect_ratio;
    t_point3d   lookat;
}	t_camera;

void    print_camera(void *cam);
void    clean_camera(void *cam);
void    init_camera(void *cam);
void    cam_more_info(t_camera *camera);

#endif