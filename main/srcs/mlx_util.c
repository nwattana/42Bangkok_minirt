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


/// @brief function handle close window
int    mlx_my_close(int key, t_mlx_confix *vars)
{
    (void)key;
    if (vars->is_init_img)
        mlx_destroy_image(vars->mlx, vars->img.img);
    if (vars->is_initwin)
        mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
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

void ppixel(t_mlx_confix *vars, int x, int y, int color)
{
    t_monitor m;

    m = vars->monitor;
    // x < min
    if (x < m.m_min_x || x > m.m_max_x || y < m.m_min_y || y > m.m_max_y)
    {
        printf("min x %d\n", m.m_min_x);
        printf("max x %d\n", m.m_max_x);
        printf("min y %d\n", m.m_min_y);
        printf("max y %d\n", m.m_max_y);
        printf("x = %d, y = %d\n", x, y);
        terror("Error over monitor size put");
        return ;
    }
    mlx_my_putpixel(&vars->img, x + m.m_x_o, m.m_y_o - y, color);
}
