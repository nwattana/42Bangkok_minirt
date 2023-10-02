#ifndef RAY_H
#define RAY_H
#include "minirt.h"

// raw = destination - origin
// direction = normalize(raw)
// len = length(raw)
typedef struct s_ray
{
    t_point3d origin;
    t_point3d destination;
    t_vec3d raw;
    t_vec3d direction;
    double  len;
    int     is_init;
} t_ray;

void    print_ray(t_ray *ray);
void    print_ray_small(t_ray *ray);
int     generate_ray(t_ray *m_ray, t_camera *s_cam, double p_x, double p_y);
int    get_point_on_ray(t_point3d *res, t_ray *ray, double dist);
#endif