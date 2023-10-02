#include "../../inc/minirt.h"


void    init_camera(void *cam)
{
    t_camera *camera;
    t_vec3d     temp;

    camera = (t_camera *)cam;
    // HOW to calculate vector up
    camera->aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
    camera->image_width = WINDOW_WIDTH;
    camera->image_height = WINDOW_HEIGHT;

    camera->viewport_height = VIEWPORT_HEIGHT;
    camera->viewport_width = camera->aspect_ratio * camera->viewport_height;

    camera->focal_len = CAMERA_LEN;
    vec3d_init(&camera->origin, 0,0,0);
    vec3d_init(&camera->horizontal, camera->viewport_width, 0, 0);
    vec3d_init(&camera->vertical, 0, camera->viewport_height, 0);

    vec3d_scale(&temp, 0.5, &camera->horizontal);
    vec3d_minus(&camera->lower_left_coner, &camera->origin, &temp);
    vec3d_scale(&temp, 0.5, &camera->vertical);
    vec3d_minus(&camera->lower_left_coner, &camera->lower_left_coner, &temp);
    vec3d_init(&temp, 0,0, camera->focal_len);
    vec3d_minus(&camera->lower_left_coner, &camera->lower_left_coner, &temp);
}

int camera_lookat(t_vec3d *poi, t_camera *camera, double length)
{
    vec3d_add(poi, &camera->normal);
    vec3d_scale(poi, length, poi);
    vec3d_add(poi, &camera->position);
}