#include "../../inc/minirt.h"

int prep_exit(t_prog *prog)
{
    t_list  *lst;

    lst = prog->obj;
    ft_lstiter(lst, clean_object_from_list);
    lst = NULL;

	return (SUCCESS);
}

int kb_talk(char *mess, int nl)
{
    printf(BLUE"Key"CLOSE);
    printf(": %s", mess);
    if (nl)
    {
        printf("\n");
    }
    return (SUCCESS);
}
