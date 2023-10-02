#include "../../inc/minirt.h"

void    print_camera(void *cam)
{
    t_camera *camera;

    camera = (t_camera *)cam;
    printf(H_LINE);
    printf("Camera:\n");
    printf("  camera position: %f, %f, %f\n", camera->position.x, camera->position.y, camera->position.z);
    printf("  camera normal:   %f, %f, %f\n", camera->normal.x, camera->normal.y, camera->normal.z);
    printf(H_LINE);
}

void cam_more_info(t_camera *camera)
{
    printf("  camera cam_up:   %f, %f, %f\n", camera->cam_up.x, camera->cam_up.y, camera->cam_up.z);
    printf("  camera projection_screen_u:   %f, %f, %f\n", camera->projection_screen_u.x, camera->projection_screen_u.y, camera->projection_screen_u.z);
    printf("  camera projection_screen_v:   %f, %f, %f\n", camera->projection_screen_v.x, camera->projection_screen_v.y, camera->projection_screen_v.z);
    printf("  camera focal_len:   %f\n", camera->focal_len);
    printf("  camera screen_width:   %f\n", camera->screen_width);
    printf("  camera screen_height:   %f\n", camera->screen_height);
    printf("  camera screen_center:   %f, %f, %f\n", camera->screen_center.x, camera->screen_center.y, camera->screen_center.z);
}
