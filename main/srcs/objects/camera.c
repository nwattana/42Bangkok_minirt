#include "../../inc/minirt.h"

void    print_camera(void *cam)
{
    t_camera *camera;

    camera = (t_camera *)cam;
    printf(H_LINE);
    printf("Camera:\n");
    printf("  camera position: %f, %f, %f\n", camera->position.x, camera->position.y, camera->position.z);
    printf("  camera normal:   %f, %f, %f\n", camera->normal.x, camera->normal.y, camera->normal.z);
    printf("  camera fov:      %f degree %f radius\n", camera->fov, camera->fov_rad);
    printf("  camera is_init:  %d\n", camera->is_init);
    cam_more_info(camera);
    printf(H_LINE);
}

void cam_more_info(t_camera *camera)
{
    if (camera->is_init == 0 && DEBUG)
        return ;
    printf("  camera cam_up:   %f, %f, %f\n", camera->cam_up.x, camera->cam_up.y, camera->cam_up.z);
    printf("  camera projection_screen_u:   %f, %f, %f\n", camera->projection_screen_u.x, camera->projection_screen_u.y, camera->projection_screen_u.z);
    printf("  camera projection_screen_v:   %f, %f, %f\n", camera->projection_screen_v.x, camera->projection_screen_v.y, camera->projection_screen_v.z);
    printf("  camera cam_len:   %f\n", camera->cam_len);
    printf("  camera screen_width:   %f\n", camera->screen_width);
    printf("  camera screen_height:   %f\n", camera->screen_height);
    printf("  camera screen_center:   %f, %f, %f\n", camera->screen_center.x, camera->screen_center.y, camera->screen_center.z);
}

void    clean_camera(void *cam)
{
    t_camera *camera;

    camera = (t_camera *)cam;
    free(camera);
}

void    init_camera(void *cam)
{
    t_camera *camera;
    t_vec3d     temp;

    camera = (t_camera *)cam;
    camera->is_init = 1;
    // HOW to calculate vector up
    camera->cam_len = CAMERA_LEN;
    camera->aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
    camera->horizontal = HORIZONTAL_SIZE;

    vec3d_init(&(camera->cam_up), 0, 0, 1);

    vec3d_cross(&(camera->projection_screen_u), &(camera->normal), &(camera->cam_up));
    vec3d_normalize(&(camera->projection_screen_u));

    vec3d_cross(&(camera->projection_screen_v), &(camera->projection_screen_u), &(camera->normal));
    vec3d_normalize(&(camera->projection_screen_v));

    vec3d_scale(&(camera->projection_screen_u), camera->horizontal, &(camera->projection_screen_u));
    vec3d_scale(&(camera->projection_screen_v), camera->horizontal / camera->aspect_ratio, &(camera->projection_screen_v));

    // UNUSED

    vec3d_scale(&temp, camera->cam_len, &(camera->normal));
    vec3d_add(&camera->screen_center, &temp);
    vec3d_add(&camera->screen_center, (t_vec3d *)&(camera->position));
}

