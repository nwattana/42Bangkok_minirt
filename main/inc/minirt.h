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

#define PROGRAM_NAME "miniRT"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		endian;
}				t_img;

typedef struct    s_mlx_confix
{
    void	*mlx;
    void	*win;
    t_img	img;
    int     is_initmlx;
    int     is_init_img;
    int     is_initwin;
}				t_mlx_confix;

typedef struct s_input
{
    t_list *obj;
    int    obj_count;
}            t_input;

// VECTOR
int vector_init(t_vector *a, double x, double y, double z);
int vector_assign(t_vector *to, t_vector *from);
int vector_add(t_vector *a, t_vector *b);
t_vector* vector_plus(t_vector *res, t_vector *a, t_vector *b);
t_vector* vector_minus(t_vector *res, t_vector *a, t_vector *b);

// MLX
void    mlx_my_putpixel(t_img *data, int x, int y, int color);
void    mlx_my_init(t_mlx_confix *vars);
int     mlx_my_close(int key, t_mlx_confix *vars);
void    mlx_my_loop(t_mlx_confix *vars);

#endif