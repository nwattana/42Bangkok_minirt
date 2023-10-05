#include "../../inc/minirt.h"
int almost_equal(double a, double b);
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


// NOTE : not complete
int     pl_test_intersection(void *object, t_interparam *param)
{
    t_vec3d     *ray;
    double      dot;
    t_plane     *plane;
    t_object    *obj;
    t_vec3d     inters_point;
    double      dist;

    obj = (t_object *)object;
    plane = (t_plane *)obj->object;
    ray = &param->ray->direction;

    dot = vec3d_dot(&plane->normal, ray);
    if (almost_equal(dot, 0))
        return (0);
    vec3d_minus(&inters_point, &plane->point, &param->ray->origin);
    dist = vec3d_dot(&inters_point, &plane->normal) / dot;
    if (param->min_dist > dist && dist > 0)
    {
        param->local_color = plane->color;
        param->min_dist = dist;
        param->inters_point.x = param->ray->origin.x + dist * ray->x;
        param->inters_point.y = param->ray->origin.y + dist * ray->y;
        param->inters_point.z = param->ray->origin.z + dist * ray->z;
        // vec3d_scale(&param->inters_normal, 1, &plane->normal);
        param->inters_normal = plane->normal;
        // DEBUG
        if (param->local_color.r == 0 && param->local_color.g == 0 && param->local_color.b == 0)
        {
            printf("plane color is 0\n");
        }
        param->inter_obj_id = obj->id;
        return (1);
    }
    return (0);
}


int almost_equal(double a, double b)
{
    return (fabs(a - b) < EPSILON);
}   