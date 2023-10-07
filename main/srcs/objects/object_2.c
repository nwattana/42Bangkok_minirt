#include "../../inc/minirt.h"

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
