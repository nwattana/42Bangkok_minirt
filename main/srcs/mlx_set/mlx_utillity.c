#include "../../inc/minirt.h"

void	mlx_my_putpixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->width + x * (data->bpp >> 3));
	*(unsigned int*)dst = color;
}

void fill_image_with_color(t_mlx_confix *vars)
{
    int win_x;
    int win_y;
    int color;

    win_y = 0;
    while (win_y < WINDOW_HEIGHT)
    {
        win_x = 0;
        while (win_x < WINDOW_WIDTH)
        {
            color = color_rgb2int(0, 0, 0);
            mlx_my_putpixel(&(vars->img), win_x, win_y, color);
            win_x++;
        }
        win_y++;
    }
}