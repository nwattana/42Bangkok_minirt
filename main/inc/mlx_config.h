#ifndef MLX_CONFIG_H
# define MLX_CONFIG_H
# include "minirt.h"

# define KEY_CTRL	256
# define KEY_SHIFT	257
# define KEY_ENTER	36
# define KEY_SPACE	49
# define KEY_ESC	53
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_W		13
# define KEY_E      14
# define KEY_R      15
# define KEY_Q      12
# define KEY_1      18
# define KEY_2      19
# define KEY_3      20
# define KEY_4      21
# define KEY_5      23
# define KEY_6      22
# define KEY_7      26
# define KEY_8      28
# define KEY_9      25
# define KEY_0      29
# define KEY_PLUS	24
# define KEY_MINUS	27
# define KEY_TAB    48
# define ACTIVE_Z 6
# define ACTIVE_X 7
# define ACTIVE_Y 8

typedef struct s_prog t_prog;

typedef struct	s_img
{
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


void    mlx_my_putpixel(t_img *data, int x, int y, int color);
void    mlx_my_init(t_mlx_confix *vars);
void    fill_image_with_color(t_mlx_confix *vars);
int	    keyhandler(int keycode, t_prog *prog);


#endif