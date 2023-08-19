#include "../inc/minirt.h"

/// @brief mlx_my_putpixel is a function that put a pixel in the image.
/// @param img_data
/// @param width line length
/// @param bpp bits per pixel
/// @param color 
void	mlx_my_putpixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->width + x * (data->bpp >> 3));
	*(unsigned int*)dst = color;
}

/// @brief init mlx window and image
void    mlx_my_init(t_mlx_confix *vars)
{
    vars->mlx = mlx_init();
    vars->is_initmlx = 1;
    vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, PROGRAM_NAME);
    vars->is_initwin = 1;
    vars->img.img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, &vars->img.width, &vars->img.endian);
    vars->is_init_img = 1;
}

/// @brief function handle close window
int    mlx_my_close(int key, t_mlx_confix *vars)
{
    (void)key;
    if (vars->is_init_img)
        mlx_destroy_image(vars->mlx, vars->img.img);
    if (vars->is_initwin)
        mlx_destroy_window(vars->mlx, vars->win);
    if (vars->is_initmlx)
        mlx_destroy_display(vars->mlx);
    return (0);
}

/// @brief function handle loop
void mlx_my_loop(t_mlx_confix *vars)
{
    // TODO Bug When exist
    mlx_hook(vars->win, 2, 0, mlx_my_close, vars);
    // X red
    mlx_hook(vars->win, 17, 0, mlx_my_close, vars);

    mlx_loop(vars->mlx);
}