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
#include "color.h"
#include "camera.h"
#include "object.h"
#include "mlx_config.h"
#include "prog_state.h"
#include "ambient.h"
#include "light.h"
#include "ray.h"
#include "sphere.h"

#define PROGRAM_NAME "miniRT"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define PI 3.14159265358979323846f
#define DEBUG 1

typedef struct s_prog
{
	int		p_state;
	int		p_error;
	t_list	*obj;
	t_mlx_confix	mlx_config;

	int		has_camera;
	int		has_ambient;
	int		has_light;
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

t_object	*create_object_camera(t_camera *cam);
t_object	*create_object_ambient(t_ambient *a);

t_object	*create_object_light(t_light *l);
t_object    *create_object_sphere(t_sphere *sp);


// STATE 10
void	prog_init_mlx(t_prog *prog);


// STATE 12
int	render_image(t_prog *prog);

int     loop_test_object(t_prog *prog, t_interparam *param);

// MLX Loop
void    prog_mlx_loop(t_prog *prog);


void  debug_message(char *msg);
#endif
