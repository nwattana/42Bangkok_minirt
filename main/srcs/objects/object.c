#include "../../inc/minirt.h"

void    print_object_from_list(void *list)
{
    t_object    *object;
    t_list      *lst;

    if (list == NULL)
    {
        printf("NULL list was passed into print_object_fromlist\n");
        return ;
    }
    lst = (t_list *)list;
    object = lst->content;
    object->print(object->object);
}

void    print_object_iter(void *content)
{
    t_object *object;

    object = (t_object *)content;
    object->print(object->object);
}

void    clean_object_from_list(void *obj)
{
    t_object *object;

    if (obj == NULL)
    {
        printf("NULL list was passed into clean_object_from_list\n");
        return ;
    }
    object = (t_object *)obj;
    if (object->clean == NULL)
    {
        printf("object->clean type %d is NULL\n", object->type);
        return ;
    }
    object->clean(object->object);
    free(object);
}

void    *get_object_from_list(t_list *lst, int type)
{
    t_object    *object;

    while (lst != NULL)
    {
        object = lst->content;
        if (object->type == type)
            return (object);
        lst = lst->next;
    }
    return (NULL);
}

int   none_test_intersection(void *obj, t_interparam *param)
{
    (void)obj;
    (void)param;

    printf("this oject has no test intersection function\n");
    exit(ERROR);
}

int init_intersection_param(t_interparam *p)
{
    p->min_dist = INFINITY;
    p->color = 0;
    p->intensity = 0;
    p->intsct_obj_id = -1;
    return (SUCCESS);
}