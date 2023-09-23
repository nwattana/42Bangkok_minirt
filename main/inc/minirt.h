#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../lib/libft.h"
#include "../lib/get_next_line.h"
#include "../mlx/mlx.h"
#include "vector.h"
#include "mlx_config.h"
#include "minirt_struct.h"
#include "prog_state.h"
#include "object.h"
#include "camera.h"

#define PROGRAM_NAME "miniRT"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct s_prog
{
	int		p_state;
	int		p_error;
	t_list	*obj;

	int		has_camera;
}	t_prog;

// prog util
int		validate_args(int argc, char **argv, t_prog *prog);
int		prog_constructor(t_prog *prog);
void	error_exit(char *msg, t_prog *prog);
int		read_rt_file(char *filepath, t_prog *prog);
int		check_line(char *line, t_prog *prog);
int		check_line_type(char **splited_lint, t_prog *prog);
int		read_2bytes(char *line);

int collect_camera(char **splited_lint, t_prog *prog);

// void	error_file(char *msg);
// static void	*get_input(char **data, char *file);
// void	read_input(t_input *data, char *file);
#endif
