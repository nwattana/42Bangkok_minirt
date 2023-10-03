#include "../../inc/minirt.h"


void    init_camera(t_camera *camera)
{
    // HOW to calculate vector up
    camera->image_width = WINDOW_WIDTH;
    camera->image_height = WINDOW_HEIGHT;
}

int camera_lookat(t_vec3d *poi, t_camera *camera, double length)
{
    vec3d_add(poi, &camera->normal);
    vec3d_scale(poi, length, poi);
    vec3d_add(poi, &camera->position);
}