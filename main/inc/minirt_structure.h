#ifndef MINIRT_STRUCTURE_H
# define MINIRT_STRUCTURE_H


typedef struct s_vector
{
    double	x;
    double	y;
    double	z;
}	t_vector;

typedef struct s_color
{
    int	red;
    int	green;
    int	blue;
}	t_color;

typedef struct s_resolution
{
    int	width;
    int	height;
}	t_resolution;

typedef struct s_ambient
{
    double	ratio;
    t_color	color;
}	t_ambient;

typedef struct s_camera
{
    t_vector	origin;
    t_vector	orientation;
    int		fov;
}	t_camera;

typedef struct s_light
{
    t_vector	origin;
    double	ratio;
    t_color	color;
}	t_light;

typedef struct s_sphere
{
    t_vector	origin;
    double	diameter;
    t_color	color;
}	t_sphere;

typedef struct s_plane
{
    t_vector	origin;
    t_vector	orientation;
    t_color	color;
}	t_plane;


typedef struct s_square
{
    t_vector	origin;
    t_vector	orientation;
    double	size;
    t_color	color;
}	t_square;


typedef struct s_cylinder
{
    t_vector	origin;
    t_vector	orientation;
    double	diameter;
    double	height;
    t_color	color;
}	t_cylinder;

#endif