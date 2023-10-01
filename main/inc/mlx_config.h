#ifndef MLX_CONFIG_H
# define MLX_CONFIG_H
# include "minirt.h"

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
int     mlx_my_close(int key, t_mlx_confix *vars);
void    fill_image_with_color(t_mlx_confix *vars);


#endif