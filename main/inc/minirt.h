#ifndef MINIRT_H
# define MINIRT_H

#include "../lib/libft.h"
#include "../lib/get_next_line.h"
#include "../mlx/mlx.h"
#include "./minirt_struct.h"
#include "./minirt_constant.h"
#include "input.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		endian;
}				t_img;

/// @brief collection of monitor qol
/// @param m_x_o is the monitor's origin x
/// @param m_y_o is the monitor's origin y
typedef struct s_monitor
{
	int		m_x_o;
	int		m_y_o;
	int		m_min_x;
	int		m_max_x;
	int		m_min_y;
	int		m_max_y;
	double	aspect_ratio;
	double	fov;
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

typedef struct s_prog
{
	int		isinit;
	int		isrender;
	int		isidle;
	t_mlx_confix	mlx;
}			t_prog;


// VECTOR
int vector_init(t_vector *a, double x, double y, double z);
int vector_assign(t_vector *to, t_vector *from);
int vector_add(t_vector *a, t_vector *b);
t_vector* vector_plus(t_vector *res, t_vector *a, t_vector *b);
t_vector* vector_minus(t_vector *res, t_vector *a, t_vector *b);
double  vector_len(t_vector *vector);
t_vector *vector_normalize(t_vector *res, t_vector *from);

// RAY
void    coor_screen_to_cam(t_monitor_coord *cam, t_monitor *monitor, double x, double y, double fov);
// MLX
void    mlx_my_putpixel(t_img *data, int x, int y, int color);
int     mlx_my_close(int key, t_mlx_confix *vars);
void    mlx_my_loop(t_prog *vars);
void	ppixel(t_mlx_confix *vars, int x, int y, int color);
int	key_hook(int keycode, t_prog *vars);
// Init
void    init_monitor(t_monitor *monitor);
void    init_my_mlx(t_mlx_confix *vars);

void	error_file(char *msg);
static void	*get_input(char **data, char *file);
void	read_input(t_input *data, char *file);
void terror(char *str);

// DEBUG
void debug_monitor_value(t_monitor *mor);


// color
int	create_trgb(int t, int r, int g, int b);
int	create_rgb(int r, int g, int b);
#endif