#include "../../inc/minirt.h"

/// @brief genearte ray from x, y coordinate on screen
/// @param m_ray memory for ray struct
/// @param s_cam source for camera data
/// @param p_x projection screen x coordinate
/// @param p_y projection screen y coordinate
/// return 0 if success, 1 if fail
int generate_ray(t_ray *m_ray, t_camera *s_cam, double p_x, double p_y)
{
    t_vec3d     temp;
    t_vec3d     temp2;
    t_point3d   world_coord;

    if (m_ray == NULL || s_cam == NULL)
        return (1);
    vec3d_assign(&(m_ray->origin), &s_cam->position);
    // compute the location of the screen point in world coordinates

    // world_coord = screen_center + p_y * projection_screen_v + p_x * projection_screen_u
    vec3d_scale(&temp, p_x, &(s_cam->projection_screen_u));
    vec3d_scale(&temp2, p_y, &(s_cam->projection_screen_v));
    vec3d_assign(&world_coord, &temp);
    vec3d_add(&world_coord, &temp2);
    vec3d_add(&world_coord, &(s_cam->screen_center));

    // ray 
    // use along with camera position to compute ray
    vec3d_minus(&(m_ray->direction), &world_coord, &(s_cam->position));

    // NOTE in this line direction not normalized raw = WorldCoord - camera.position
    vec3d_assign(&(m_ray->raw), &(m_ray->direction));

    m_ray->len = vec3d_length(&(m_ray->direction));
    // DEBUG normalize
    if (vec3d_length(&(m_ray->direction)) == 0)
        return (1);
    vec3d_normalize(&(m_ray->direction));
    if (vec3d_normalize(&(m_ray->direction)) == 1)
    {
        printf("ray.c1\n");
        exit(0);
    }
    vec3d_assign(&(m_ray->destination), &world_coord);
    vec3d_assign(&(m_ray->origin), &(s_cam->position));

    return (0);
}

void    print_ray(t_ray *ray)
{
    printf(H_LINE);
    printf("ray origin: %f, %f, %f\n", ray->origin.x, ray->origin.y, ray->origin.z);
    printf("ray destination: %f, %f, %f\n", ray->destination.x, ray->destination.y, ray->destination.z);
    printf("ray direction: %f, %f, %f\n", ray->direction.x, ray->direction.y, ray->direction.z);
    printf("ray len: %f\n", ray->len);
    printf("ray raw: %f, %f, %f\n", ray->raw.x, ray->raw.y, ray->raw.z);

    printf(H_LINE);
}

void    print_ray_small(t_ray *ray)
{
    printf("[%.3f %.3f %.3f]\n", ray->raw.x, ray->raw.y, ray->raw.z);
}

int    get_point_on_ray(t_point3d *res, t_ray *ray, double dist)
{
    vec3d_assign(res, &(ray->direction));
    vec3d_scale(res, dist, res);
    vec3d_add(res, &(ray->origin));

    return (1);
}

int create_ray_from_points(t_ray *ray, t_point3d *origin, t_point3d *destination)
{
    vec3d_assign(&(ray->origin), origin);
    vec3d_assign(&(ray->destination), destination);
    vec3d_minus(&(ray->raw), destination, origin);
    vec3d_assign(&(ray->direction), &(ray->raw));
    // DEBUG normalize
    if (vec3d_length(&(ray->direction)) == 0)
    {
        debug_message("ray direction length is 0: create_ray_from_points");
        return (1);
    }
    vec3d_normalize(&(ray->direction));
    ray->len = vec3d_length(&(ray->raw));

    return (SUCCESS);
}