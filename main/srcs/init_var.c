#include "../inc/minirt.h"

/// @brief init mlx window and image
void    init_my_mlx(t_mlx_confix *vars)
{
    vars->mlx = mlx_init();
    vars->is_initmlx = 1;
    vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, PROGRAM_NAME);
    vars->is_initwin = 1;
    vars->img.img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, &vars->img.width, &vars->img.endian);
    vars->is_init_img = 1;
    init_monitor(&vars->monitor);

}

void    init_monitor(t_monitor *mor)
{
    mor->m_max_x = WINDOW_WIDTH / 2;
    mor->m_max_y = WINDOW_HEIGHT / 2;
    mor->m_min_x = -WINDOW_WIDTH / 2;
    mor->m_min_y = -WINDOW_HEIGHT / 2;
    mor->m_x_o = WINDOW_WIDTH / 2;
    mor->m_y_o = WINDOW_HEIGHT / 2;
}