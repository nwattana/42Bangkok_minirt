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
    // t_ray cal;
    // t_vec3d temp;
    // t_object *obj;

    // obj = (t_object *)object;
    // apply_tfmat_to_ray(&cal, &obj->tfmat, &param->ray, BWD);
    
    // vec3d_assign(&temp, &cal.direction);
    // vec3d_normalize(&temp);

    // // Check intersection with plane cast ray not pallel with plane
    // if (almost_equal(temp.z, 0))
    //     return (0);
    // double t;

    // vec3d_normalize(&cal.origin);

    // t = -cal.origin.z / temp.z;

    // if (t > 0.0)
    // {
    //     double u;
    //     double v;

    //     u = cal.origin.x + t * temp.x;
    //     v = cal.origin.y + t * temp.y;

    //     if (abs(u) < 1 && abs(v) < 1)
    //     {
    //         t_vec3d point;
    //         vec3d_scale(&point, t, &temp);
    //         vec3d_add(&point, &cal.origin);

    //         // convert 0,0,0 normal 0,0,-1 with tfmat to global coor
    //         t_vec3d     localorigin;
    //         t_vec3d     normal;
    //         t_vec3d     globalorigin;

    //         vec3d_init(&localorigin, 0, 0, 0);
    //         vec3d_init(&normal, 0, 0, -1);
    //         apply_tfmat_to_vec(&globalorigin, &obj->tfmat, &localorigin, FWD);
    //         apply_tfmat_to_vec(&(param->local_normal), &obj->tfmat, &normal, FWD);

    //         t_vec3d test;
    //         mul_mat_to_vector_2(&test, &obj->tfmat.fwd, &normal);
    //         vec3d_normalize(&test);
    //         print_vec3d(&test);
    //         vec3d_minus(&(param->local_normal), &(param->local_normal), &globalorigin);
    //         vec3d_normalize(&param->local_normal);
            
    //         t_plane *pl;
    //         pl = (t_plane *)obj->object;
    //         color_copy(&param->local_color, &pl->color);

    //         return (1);
    //     }
    // }
    return (0);
}