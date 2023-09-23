#ifndef OJBECT_H
# define OBJECT_H

# include "minirt.h"

# define CAMERA 1
# define AMBIENT 2
# define LIGHT 3
# define SPHERE 4

typedef struct s_object
{
    int		type;
    void	*object;

    void    (*print)(void *object);
    void    (*clean)(void *object);
}	t_object;

t_object    *new_object(int type, void *object, void (*print)(void *object));
void    print_object_from_list(void *lst);
void    clean_object_from_list(void *obj);

void    print_object_iter(void *content);


#endif