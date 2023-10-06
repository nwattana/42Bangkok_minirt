#include "../../inc/minirt.h"

void    print_cylinder(void *object)
{
    t_cylinder *cylinder;

    cylinder = (t_cylinder *)object;
    printf("cylinder: \n");
    print_vec3d(&cylinder->point,"point: ");
    print_vec3d(&cylinder->normal,"normal: ");
    printf("radius: %f\n", cylinder->radius);
    printf("height: %f\n", cylinder->height);
    print_color(&cylinder->color);
}

void    clean_cylinder(void *object)
{
    t_cylinder *cylinder;

    cylinder = (t_cylinder *)object;
    free(cylinder);
}

int     cy_test_intersection(void *object, t_interparam *p)
{
    t_cylinder *cy;
    t_object *obj;
    t_ray   *ray;

    obj = (t_object *)object;
    cy = (t_cylinder *)obj->object;
    ray = p->ray;

    if (p->f_ishit)
        return (1);
    return (0);
    
}
