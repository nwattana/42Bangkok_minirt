#include "../../inc/minirt.h"

void    print_plane(void    *pl)
{
    t_plane *plane;

    plane = (t_plane *)pl;
    printf(H_LINE);
    printf("Plane:\n");
    printf("  plane point:  %f, %f, %f\n", plane->point.x, plane->point.y, plane->point.z);
    printf("  plane normal: %f, %f, %f\n", plane->normal.x, plane->normal.y, plane->normal.z);
    printf("  plane color:  %d, %d, %d\n", plane->color.r, plane->color.g, plane->color.b);
    printf(H_LINE);
}

void    clean_plane(void *pl)
{
    t_plane *plane;

    plane = (t_plane *)pl;
    free(plane);
}


// plane on XY at 0,0,0

int     pl_test_intersection(void *object, t_interparam *param)
{
    t_ray       cal;
    t_object    *obj;
    t_plane     *pl;
    double      b;

    obj = (t_object *)object;
    pl = (t_plane *)obj->object;

    ft_memcpy(&cal, &param->ray, sizeof(t_ray));
    b = vec3d_dot(&cal.direction, &(pl->normal));
    if (almost_equal(b, 0))
    {
        debug_message("plane is parallel to ray");
        return (0);
    }

    t_vec3d p0_l0;
    vec3d_minus(&p0_l0, &cal.origin, &(pl->point));
    double  parametric_distance;

    parametric_distance = -vec3d_dot(&p0_l0, &(pl->normal)) / b;

    if (parametric_distance >= 0.0)
    {

        // param->intersection_point
        vec3d_scale(&param->intersection_point, parametric_distance, &cal.direction);
        vec3d_add(&param->intersection_point, &cal.origin);

        // param->normal
        vec3d_assign(&param->local_normal, &(pl->normal));
        vec3d_normalize(&param->local_normal);

        // param->color
        ft_memcpy(&param->color, &(pl->color), sizeof(t_color));
        ft_memcpy(&param->local_color, &(pl->color), sizeof(t_color));

        param->intersection_obj = obj;
        return (1);
    }
    return (0);
}
