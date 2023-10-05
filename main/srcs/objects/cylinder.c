#include "../../inc/minirt.h"

void   print_cylinder(void *cy)
{
    t_cylinder *cylinder;

    cylinder = (t_cylinder *)cy;
    printf(H_LINE);
    printf("Cylinder: %f\n", cylinder->radius);
    printf("Cylinder: %f\n", cylinder->hight);
    printf("  cylinder pos: %f, %f, %f\n", cylinder->position.x, cylinder->position.y, cylinder->position.z);
    printf("  cylinder direc: %f, %f, %f\n", cylinder->direction.x, cylinder->direction.y, cylinder->direction.z);
    printf("  cylinder color:  %d, %d, %d\n", cylinder->color.r, cylinder->color.g, cylinder->color.b);
    printf("  cylinder radius: %f\n", cylinder->radius);
    printf(H_LINE);
}

void   clean_cylinder(void *cy)
{
    t_cylinder *cylinder;

    cylinder = (t_sphere *)cy;
    free(cylinder);
}