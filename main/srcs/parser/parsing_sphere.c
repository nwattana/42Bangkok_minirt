#include "../../inc/minirt.h"

// FIXME : handle unneeded params
int     collect_sphere(char **splited_str, t_prog *prog)
{
    t_sphere    *sphere;
    t_object    *object;

    sphere = malloc(sizeof(t_sphere));
    if (sphere == NULL)
        return (1);
    
    // center radius color
    collect_3d(splited_str[1], &sphere->center);
    ft_strtod(splited_str[2], &sphere->radius);
    sphere->radius = sqrt(sphere->radius);
    collect_color(splited_str[3], &sphere->color);

    object = create_object_sphere(sphere);
    if (object == NULL)
        return (1);
    // add sphere to object list

    sp_prep_tfmat(sphere, object);

    ft_lstadd_back(&prog->obj, ft_lstnew(object));
    return (0);
}

t_object    *create_object_sphere(t_sphere *sp)
{
    t_object *object;

    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (0);
    object->type = SPHERE;
    object->object = sp;
    object->print = print_sphere;
    object->clean = clean_sphere;
    object->test_intersection = sp_test_intersection;

    return (object);
}

int     sp_prep_tfmat(t_sphere *sp, t_object *obj)
{
    t_tfmat *tfmat;
    t_vec3d temp;

    tfmat = &(obj->tfmat);

    init_tfmat(tfmat);
    vector_to_translation(&tfmat->translate, &sp->center);
    vec3d_init(&temp, sp->radius, sp->radius, sp->radius);
    vector_to_scale_matrix(&tfmat->scale_metrix, &temp);

    cal_tfmat_fwd(tfmat);
    cal_tfmat_bwd(tfmat);
    
    return (0);
}