#ifndef OJBECT_H
# define OBJECT_H

# include "minirt.h"

# define CAMERA 1

typedef struct s_object
{
    int		type;
    void	*object;

    void    (*print)(void *object);
}	t_object;

t_object    *new_object(int type, void *object, void (*print)(void *object));
void    print_object_from_list(t_list *lst);



#endif