#include "../../inc/minirt.h"
void    cale_middle_screen(t_camera *camera);
int collect_camera(char **splited_line, t_prog *prog);
void    cale_top_left(t_camera *cam);
int is_parallel(t_vec3d *v1, t_vec3d *v2)
{
    double dot;
    double len1;
    double len2;

    dot = vec3d_dot(v1, v2);
    len1 = vec3d_length(v1);
    len2 = vec3d_length(v2);
    if (dot == len1 * len2)
        return (1);
    else
        return (0);
}

void    init_camera(t_camera *camera)
{
    t_point3d   w;
    t_vec3d     world_up;
    double     aux_cale;

    aux_cale = 0;
    // set world up
    world_up = (t_vec3d){0,1,0};
    if (is_parallel(&camera->normal, &world_up))
    {
        world_up = (t_vec3d){0,0,1};
    }
    ft_memcpy(&camera->world_up, &world_up, sizeof(t_vec3d));
    camera->len = cale_camera_len(camera);
    camera->aspect_ratio = WINDOW_WIDTH / WINDOW_HEIGHT;
    cale_middle_screen(camera);
    cale_top_left(camera);
}

void    cale_top_left(t_camera *cam)
{
    t_vec3d left;
    t_vec3d top;

    // middle_screem
    vec3d_scale(&left, WINDOW_WIDTH / 2, &cam->cam_left);
    vec3d_minus(&left, &cam->middle_screen, &left);
    vec3d_scale(&top, WINDOW_HEIGHT / 2, &cam->cam_up);
    vec3d_plus(&cam->top_left, &left, &top);
}

// len in pixel unit
double cale_camera_len(t_camera *camera)
{
    double  len;
    double  aux_cale;

    if (camera->fov > 180 || camera->fov < 0)
    {
        debug_message("fov must be between 0 and 180\n");
        exit(1);
    }
    aux_cale = camera->fov / 2;
    aux_cale = aux_cale * PI / 180;
    aux_cale = tan(aux_cale);
    len = (WINDOW_WIDTH / (2 * aux_cale));
    return (len);
}

void    cale_middle_screen(t_camera *camera)
{
    t_vec3d     aux;
    t_vec3d     aux2;

    // cam_origin
    ft_memcpy(&aux, &camera->position, sizeof(t_vec3d));

    // len x normal
    vec3d_scale(&aux2, camera->len, &camera->normal);

    // v_cam + len x normal = world_2_middle_screen or cam_to_screen
    vec3d_plus(&camera->middle_screen, &aux, &aux2);

    // screen_up = cam2screen x world_2_screen
    vec3d_cross(&camera->cam_up, &camera->normal, &camera->world_up);
    if (vec3d_normalize(&camera->cam_up))
    {
        print_vec3d(&camera->cam_up, "cam_up");
        debug_message("normalize cam_up failed: cale_middle_screen\n");
    }

    // screen_left = cam2screen x screen_up
    vec3d_cross(&camera->cam_left, &camera->normal, &camera->cam_up);
    if (vec3d_normalize(&camera->cam_left))
    {
        print_vec3d(&camera->cam_left, "cam_left");
        debug_message("normalize cam_left failed: cale_middle_screen\n");
    }
}


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