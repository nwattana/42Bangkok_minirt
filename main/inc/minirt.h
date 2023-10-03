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
#include "matrix.h"
#include "color.h"
#include "camera.h"
#include "object.h"
#include "mlx_config.h"
#include "prog_state.h"
#include "ambient.h"
#include "light.h"
#include "ray.h"
#include "sphere.h"
#include "plane.h"

#define PROGRAM_NAME "miniRT"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define PI 3.14159265358979323846f
#define DEBUG 1

/// @brief a Default value for testing and debugging
typedef struct s_defval
{
	t_vec3d vec_111;
	t_color color_purple;
	t_color color_white;
}		t_defval;

typedef struct s_renderer
{

	double		xfact;
	double		yfact;
	double		norm_x;
	double		norm_y;
	int			has_intersection;

	int			color;
	double 		min_dist;
	double 		max_dist;
	t_vec3d 	origin_to_intersection;
	t_object	*cam;
	double 		dist;

}			t_renderer;

typedef struct s_prog
{
	int				p_state;
	int				p_error;
	t_list			*obj;
	t_mlx_confix	mlx_config;
	t_defval 		defval;


	// Single only object;
	t_camera	camera;
	t_light		light;
	t_ambient	ambient;
	t_color	ambient_color;
	int		item;

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
int		almost_equal(double a, double b);

int		collect_camera(char **splited_line, t_prog *prog);
int     collect_ambient(char **split_line, t_prog *prog);
int		collect_light(char **splited_line, t_prog *prog);
int     collect_sphere(char **splited_line, t_prog *prog);
int		collect_plane(char **str, t_prog *prog);

int     sp_prep_tfmat(t_sphere *sp, t_object *obj);

t_object	*create_object_camera(t_camera *cam);
t_object	*create_object_ambient(t_ambient *a);

t_object	*create_object_light(t_light *l);
t_object    *create_object_sphere(t_sphere *sp);
t_object	*create_object_plane(t_plane *plane);

double solve_quadratic(double a, double b, double c);

// STATE 10
void	prog_init_mlx(t_prog *prog);


// STATE 12
// t_renderer
int  init_renderer(t_renderer *ren, t_prog *prog);


int	render_image(t_prog *prog);

int     loop_test_object(t_prog *prog, t_interparam *param);

int		apply_tfmat_to_ray(t_ray *res, t_tfmat *mat, t_ray *in_ray, int dir);
int		apply_tfmat_to_vec(t_vec3d *res, t_tfmat *mat, t_vec3d *in_vec, int dir);
int		mul_mat_to_vector_2(t_vec3d *res, t_mat44 *tmp, t_vec3d *in_vec);
int loop_test_light(t_prog *prog, t_interparam *param, t_ray *inter_to_light);
void  init_light_intersection_param(t_interparam *param, t_prog *prog, t_interparam *inter);
int		which_color_should_be(t_prog *prog, int x, int y, t_renderer *renderer);
int	cal_light(t_prog *prog, t_renderer *renderer, t_interparam *param);
int	init_intersection_param(t_interparam *param, t_prog *prog);
// MLX Loop

void    prog_mlx_loop(t_prog *prog);

void  debug_message(char *msg);
#endif
