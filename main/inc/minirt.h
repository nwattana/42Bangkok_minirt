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
#include "mlx_config.h"
#include "prog_state.h"
#include "object.h"
#include "camera.h"
#include "ambient.h"
#include "light.h"

#define PROGRAM_NAME "miniRT"
#define WINDOW_WIDTH 1280.0
#define WINDOW_HEIGHT 720.0

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


int		collect_camera(char **splited_lint, t_prog *prog);
int     collect_ambient(char **split_line, t_prog *prog);
int		collect_light(char **splited_line, t_prog *prog);
// STATE 10
void	prog_init_mlx(t_prog *prog);


// STATE 12
void	render_image(t_prog *prog);
int     gen_color_xy(int win_x, int win_y, t_prog *prog);

// void	error_file(char *msg);
// static void	*get_input(char **data, char *file);
// void	read_input(t_input *data, char *file);
#endif
