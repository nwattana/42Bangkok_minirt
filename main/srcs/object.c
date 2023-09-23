#include "../inc/minirt.h"

t_object *new_object(int type, void *object,\
    void (*print)(void *object))
{
    t_object *new;

    new = malloc(sizeof(t_object));
    if (new == NULL)
        return (NULL);
    new->type = type;
    new->object = object;
    new->print = print;
    return (new);
}

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
    object->clean(object->object);
    free(object);
}