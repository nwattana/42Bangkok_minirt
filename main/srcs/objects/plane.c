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

int     pl_test_intersection(void *obj, t_interparam *param)
{
    // TODO 
    return (0);
}