#include "../inc/minirt.h"

void    print_camera(void *cam)
{
    t_camera *camera;

    camera = (t_camera *)cam;
    printf("camera position:\t%f,\t%f,\t%f\n", camera->position.x, camera->position.y, camera->position.z);
    printf("camera normal:\t\t%f,\t%f,\t%f\n", camera->normal.x, camera->normal.y, camera->normal.z);
    printf("camera fov:\t\t%f\n", camera->fov);
    printf("camera is_init:\t%d\n", camera->is_init);
}