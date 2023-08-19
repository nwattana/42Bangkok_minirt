#include "../inc/minirt.h"
#include <wait.h>
// include sleep
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    void   *img;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// กด esc ออก
int	s_close(int keycode,  t_vars *vars)
{
    mlx_destroy_image(vars->mlx, vars->img);
    mlx_destroy_window(vars->mlx, vars->win);
    exit (0);
}

// กด x ออก window destroy อยู่แล้ว
int	t_close(int keycode,  t_vars *vars)
{
    exit (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    t_vars  vars;
	char 	str[100]="Hello world!";


    vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx , 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx , 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

    vars.img = img.img;
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_hook(vars.win, 2, 0, s_close, &vars);
    mlx_hook(vars.win, 17, 0, t_close, &vars);
	mlx_loop(vars.mlx);
}