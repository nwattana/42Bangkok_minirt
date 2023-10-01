#ifndef OJBECT_H
# define OBJECT_H

# include "minirt.h"
# include "ray.h"

# define CAMERA 1
# define AMBIENT 2
# define LIGHT 3

// TYPE more than 10 is reserved for objects
# define SPHERE 20
# define PLANE 21

typedef struct s_object t_object;

/// @brief struct to store intersection parameters
/// @param ray ray to test intersection create from camera to screen
/// @param intersection_point point of intersection
/// @param local_normal normal vector of intersection point
/// @param local_color color of intersection point
/// @param color to plot on screen
/// @param intensity of light
/// @param min_dist minimum distance to intersection point of current ray
/// @param intersection_obj closest object that intersect with current ray
typedef struct s_interparam
{
    t_ray       ray;
	t_point3d	intersection_point;
    t_vec3d		local_normal;
	t_color	    local_color;
	int			color;
    double      intensity;
    double      min_dist;
    t_object    *intersection_obj;

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

int     none_test_intersection(void *object, t_interparam *param);

#endif