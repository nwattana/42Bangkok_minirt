#ifndef OJBECT_H
# define OBJECT_H

# include "minirt.h"
# include "ray.h"

# define CAMERA 1
# define AMBIENT 2
# define LIGHT 3

// TYPE more than 10 is reserved for objects
# define SPHERE 20

/// @brief struct to store intersection parameters
typedef struct s_interparam
{
    t_ray       ray;
	t_point3d	intersection_point;
    t_vec3d		local_normal;
	t_color	    local_color;
	int			color;
    double      intensity;

}	t_interparam;

typedef struct s_object
{
    int		type;
    void	*object;
    t_tfmat     tfmat;

    void    (*print)(void *object);
    void    (*clean)(void *object);

    // Null if type < 20
    int    (*test_intersection)(void *object, t_interparam *param);

}	t_object;

void    print_object_from_list(void *lst);
void    clean_object_from_list(void *obj);
void    print_object_iter(void *content);
void    *get_object_from_list(t_list *lst, int type);

int    none_test_intersection(void *object, t_interparam *param);

#endif