#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// FIXME: change back to lib
#include "../zlib/libft.h"
#include "../zlib/get_next_line.h"
#include "../mlx/mlx.h"
#include "const_utils.h"
#include "vector.h"
#include "mlx_config.h"
#include "prog_state.h"

#define PROGRAM_NAME "miniRT"
#define WINDOW_WIDTH 640.0f
#define WINDOW_HEIGHT 360.0f
#define PI 3.14159265358979323846f
#define DEBUG 1
#define WORLD_SCALE 1.0f
typedef struct s_color
{
    int	r;
    int	g;
    int	b;
}	t_color;

# define CAMERA_LEN 1.0f


/// @brief  t_camera is a struct that contains the camera's origin, orientation, and fov.
/// @param  position is a point that contains the camera's origin.
/// @param  normal is a t_vec3d that contains the camera's orientation.
/// @param  fov is an int that contains the camera's fov.
typedef struct s_camera
{
    t_point3d   position;
    t_vec3d     normal;
    double         fov;
    double         fov_rad;

    double      len;
    double      aspect_ratio;
    t_vec3d     world_up;
    t_vec3d     look_at;
    t_vec3d     u;
    t_vec3d     v;
    t_vec3d     top_left;

}	t_camera;


typedef struct s_light
{
    t_point3d   position;
    t_color     color;
    double      intensity;
}               t_light;

typedef struct s_ray
{
    t_point3d origin;
    t_vec3d direction;
} t_ray;

typedef struct s_plane
{
    t_vec3d    point;
    t_vec3d    normal;
    t_color    color;
}   t_plane;

/// @brief struct to store intersection parameters
/// @param ray ray to test intersection create from camera to screen
/// @param intersection_point point of intersection
/// @param local_normal normal vector of intersection point
/// @param local_color color of intersection point
/// @param color to plot on screen
/// @param intensity of light
/// @param min_dist minimum distance to intersection point of current ray
/// @param intersection_obj list of object that intersect with current ray
typedef struct s_interparam
{
    t_ray       *ray;
    t_point3d   inters_point;
    t_vec3d     inters_normal;
    double      min_dist;
    double      inter_obj_id;
    t_color     local_color;
    int     is_hit;

}	t_interparam;

typedef struct	s_sphere
{
    t_point3d   center;
    double		radius;
    t_color     color;
}				t_sphere;

typedef struct s_object
{
    int		type;
    void	*object;
    int		id;
    void    (*print)(void *object);
    void    (*clean)(void *object);

    int    (*test_intersection)(void *object, t_interparam *param);
}	t_object;

typedef struct s_prog
{
	int				p_state;
	int				p_error;
	t_list			*obj;
	t_mlx_confix	mlx_config;
	int			has_camera;
	int			has_ambient;
	int			has_light;

	t_camera 	camera;
	t_light		light;
	t_color		ambient_color;
    double     ambient_intensity;

	int	item_count;
}	t_prog;

// prog util
int		validate_args(int argc, char **argv, t_prog *prog);
int		prog_constructor(t_prog *prog);
void	error_exit(char *msg, t_prog *prog);
int		read_rt_file(char *filepath, t_prog *prog);
int		check_line(char *line, t_prog *prog);
int		check_line_type(char **splited_lint, t_prog *prog);
int		read_2bytes(char *line);
int		count_char(char *str, int c);

int		collect_camera(char **splited_line, t_prog *prog);
int     collect_ambient(char **split_line, t_prog *prog);
int		collect_light(char **splited_line, t_prog *prog);
int     collect_sphere(char **splited_line, t_prog *prog);
int		collect_plane(char **str, t_prog *prog);

// set up camera
double cale_camera_len(t_camera *camera);

// Plane
void    clean_plane(void *pl);
void    print_plane(void *pl);
int     pl_test_intersection(void *obj, t_interparam *param);

// LIght
void    print_light(void *light);
void    clean_light(void *light);
int point_light(t_light *light, t_list *current_obj, t_interparam *param, t_color *color, double *intensity);

// sphere
void   print_sphere(void *sphere);
void   clean_sphere(void *sphere);
int    sp_test_intersection(void *object, t_interparam *p);

// Color
int     color_init(t_color *color, int r, int g, int b);
int     color_plus(t_color *res, t_color *a, t_color *b);
int     color_struct2int(t_color *color);
int     color_rgb2int(int r, int g, int b);
int     color_collect_string(char *color_string, t_color *color);
int     color_scale(t_color *res, double scale, t_color *a);
int     print_color(t_color *color);
int     color_plus(t_color *res, t_color *a, t_color *b);
int     color_copy(t_color *dst, t_color *src);
t_color int2color(int color);
int     color_dot(t_color *res, t_color *c1, t_color *c2);
// cam
void    init_camera(t_camera *cam);

// object
void    print_object_from_list(void *lst);
void    clean_object_from_list(void *obj);
void    print_object_iter(void *content);
void    *get_object_from_list(t_list *lst, int type);
int     none_test_intersection(void *object, t_interparam *param);
t_object    *create_object_sphere(t_sphere *sp);
t_object	*create_object_plane(t_plane *plane);

// ray
void    generate_ray(t_ray *ray, t_prog *prog, int x, int y);
int     init_intersection_param(t_prog *prog, t_ray *ray, t_interparam *param);
int     trace_ray_to_obj(t_prog *prog, t_interparam *param);
int     loop_test_ray_to_obj(t_prog *prog, t_interparam *param);
// simple math
double solve_quadratic(double a, double b, double c);

void	prog_init_mlx(t_prog *prog);
int		render_image(t_prog *prog);
void    prog_mlx_loop(t_prog *prog);
void  debug_message(char *msg);
#endif
