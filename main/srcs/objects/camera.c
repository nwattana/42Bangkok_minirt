#include "../../inc/minirt.h"
void    camera_look_at(t_camera *camera);
void    camera_right_vector(t_camera *camera);
void    camera_up_vector(t_camera *camera);
void    camera_top_left_vector(t_camera *camera);

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

    double      aux_cale;
    t_vec3d     look_at;

    aux_cale = 0;
    // set world up
    camera->len = cale_camera_len(camera);
    camera->aspect_ratio = WINDOW_WIDTH / WINDOW_HEIGHT;
    camera_look_at(camera);
    camera_up_vector(camera);
    camera_right_vector(camera);
    camera_top_left_vector(camera);
}

void    camera_look_at(t_camera *camera)
{
    t_vec3d     look_at;

    vec3d_plus(&look_at, &camera->position, &camera->normal);
    vec3d_minus(&camera->look_at, &look_at, &camera->position);
    if (vec3d_normalize(&camera->look_at))
    {
        print_vec3d(&camera->look_at, "look_at");
        debug_message("normalize look_at failed: init_camera\n");
    }
}

void    camera_top_left_vector(t_camera *cam)
{
    t_vec3d    aux;
    t_vec3d    aux2;
    t_vec3d    aux3;
    double      aux_cale;

    aux_cale = WINDOW_WIDTH / 2;
    aux_cale = aux_cale / (2.0 * tan(cam->fov * (PI/180.0) / 2.0));
    ft_memcpy(&aux, &cam->look_at, sizeof(t_vec3d));
    vec3d_normalize(&aux);
    vec3d_scale(&aux, aux_cale, &aux);
    vec3d_scale(&aux2, WINDOW_WIDTH/2, &cam->u);
    vec3d_scale(&aux3, WINDOW_HEIGHT/2, &cam->v);
    vec3d_minus(&cam->top_left, &aux, &aux2);
    vec3d_minus(&cam->top_left, &cam->top_left, &aux3);
}

void camera_up_vector(t_camera *camera)
{
    t_vec3d     world_up;

    world_up = (t_vec3d){0,1,0};
    if (is_parallel(&camera->look_at, &world_up))
    {
        debug_message("camera look_at is parallel to world_up\n");
        exit(1);
    }
    vec3d_cross(&camera->u, &camera->look_at, &world_up);
    if (vec3d_normalize(&camera->u))
    {
        debug_message("normalize u failed: init_camera\n");
        exit(1);
    }
}

void camera_right_vector(t_camera *camera)
{
    vec3d_cross(&camera->v, &camera->look_at, &camera->u);
    if (vec3d_normalize(&camera->v))
    {
        debug_message("normalize world_up failed: init_camera\n");
        exit(1);
    }
}

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