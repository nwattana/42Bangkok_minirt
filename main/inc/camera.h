#ifndef CAMERA_H
# define CAMERA_H
# include "minirt.h"

# define CAMERA_LEN 1.0
# define VIEWPORT_HEIGHT 2


/// @brief  t_camera is a struct that contains the camera's origin, orientation, and fov.
/// @param  position is a point that contains the camera's origin.
/// @param  normal is a t_vec3d that contains the camera's orientation.
/// @param  fov is an int that contains the camera's fov.
typedef struct s_camera
{
    t_point3d   position;
    // m_alignment vertor
    t_vec3d     normal;
    double         fov;

    double  image_width;
    double  image_height;
    t_vec3d     cam_up;

    double      aspect_ratio;
    double      screen_width;
    double      screen_height;
    double      viewport_height;
    double      viewport_width;
    double      focal_len;


    t_vec3d     projection_screen_u;
    t_vec3d     projection_screen_v;
    t_vec3d     u_dir;
    t_vec3d     v_dir;



    t_vec3d     horizontal;
    t_vec3d     vertical;

    t_vec3d     origin;
    t_vec3d     screen_center;
    t_vec3d     lower_left_coner;
    
}	t_camera;

int    camera_lookat(t_vec3d *poi, t_camera *camera, double length);

void    print_camera(void *cam);
void    clean_camera(void *cam);
void    init_camera(void *cam);
void    cam_more_info(t_camera *camera);

#endif