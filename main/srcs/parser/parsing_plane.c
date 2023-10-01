#include "../../inc/minirt.h"
int pl_prep_tfmat(t_plane *pl, t_object *obj);
int collect_plane(char **str, t_prog *prog)
{
    t_plane *plane;
    t_object *object;

    plane = malloc(sizeof(t_plane));
    if (plane == NULL)
        return (1);
    collect_3d(str[1], &plane->point);
    collect_3d(str[2], &plane->normal);
    collect_color(str[3], &plane->color);

    object = create_object_plane(plane);
    if (object == NULL)
        return (1);
    

    pl_prep_tfmat(plane, object);
    print_tfmat(&object->tfmat);
    ft_lstadd_back(&prog->obj, ft_lstnew(object));
    return (0);
}

t_object *create_object_plane(t_plane *plane)
{
    t_object *object;

    object = malloc(sizeof(t_object));
    if (object == NULL)
        return (0);
    object->type = PLANE;
    object->object = plane;
    object->print = print_plane;
    object->clean = clean_plane;
    object->test_intersection = pl_test_intersection;

    return (object);
}

int pl_prep_tfmat(t_plane *pl, t_object *obj)
{
    t_tfmat *tfmat;
    t_vec3d temp;

    tfmat = &(obj->tfmat);

    init_tfmat(tfmat);
    vector_to_translation(&tfmat->translate, &pl->point);
    // print arcos value
    // vec3d_init(&temp, acos(pl->normal.x), acos(pl->normal.y), acos(pl->normal.z));

    vec3d_init(&temp, pl->normal.x, pl->normal.y, pl->normal.z);

    // TODO : fix this
    vector_to_rotate_x(&tfmat->rotate_x, &temp);
    vector_to_rotate_y(&tfmat->rotate_y, &temp);
    vector_to_rotate_z(&tfmat->rotate_z, &temp);
    print_tfmat(tfmat);

    cal_tfmat_fwd(tfmat);
    cal_tfmat_bwd(tfmat);
    
    return (0);
}