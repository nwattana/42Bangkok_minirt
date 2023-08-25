#ifndef MINIRT_H
# define MINIRT_H

#include "../lib/libft.h"
#include "../lib/get_next_line.h"
#include "../mlx/mlx.h"
#include "./minirt_struct.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 
#define PROGRAM_NAME "miniRT"
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		endian;
}				t_img;

/// @brief collection of monitor qol
typedef struct s_monitor
{
	int		m_x_o;
	int		m_y_o;
	int		m_min_x;
	int		m_max_x;
	int		m_min_y;
	int		m_max_y;
}	t_monitor;

typedef struct    s_mlx_confix
{
    void	*mlx;
    void	*win;
    t_img	img;
	t_monitor monitor;
    int     is_initmlx;
    int     is_init_img;
    int     is_initwin;
}				t_mlx_confix;

typedef struct s_input
{
	t_list			*obj;
	int				obj_count;
	char			*fileinput;
	t_vector		*vector;
	t_color			*color;
	t_resolution	*res;
	t_ambient		*a;
	t_camera		*c;
	t_light			*l;
	t_sphere		*sp;
	t_plane			*pl;
	t_square		*sq;
	t_cylinder		*cy;
}	t_input;


// VECTOR
int vector_init(t_vector *a, double x, double y, double z);
int vector_assign(t_vector *to, t_vector *from);
int vector_add(t_vector *a, t_vector *b);
t_vector* vector_plus(t_vector *res, t_vector *a, t_vector *b);
t_vector* vector_minus(t_vector *res, t_vector *a, t_vector *b);

// MLX
void    mlx_my_putpixel(t_img *data, int x, int y, int color);
int     mlx_my_close(int key, t_mlx_confix *vars);
void    mlx_my_loop(t_mlx_confix *vars);
void	ppixel(t_mlx_confix *vars, int x, int y, int color);

// Init
void    init_monitor(t_monitor *monitor);
void    init_my_mlx(t_mlx_confix *vars);

void	error_file(char *msg);
static void	*get_input(char **data, char *file);
void	read_input(t_input *data, char *file);

void terror(char *str);

#endif
