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

void    print_object_from_list(t_list *lst)
{
    t_object *object;

    if (lst == NULL)
    {
        printf("NULL list was passed into print_object_fromlist\n");
        return ;
    }
    object = lst->content;
    object->print(object->object);
}