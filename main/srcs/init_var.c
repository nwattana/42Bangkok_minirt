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
    mor->aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
}

void debug_monitor_value(t_monitor *mor)
{
    printf("m_max_x = %d\n", mor->m_max_x);
    printf("m_max_y = %d\n", mor->m_max_y);
    printf("m_min_x = %d\n", mor->m_min_x);
    printf("m_min_y = %d\n", mor->m_min_y);
    printf("m_x_o = %d\n", mor->m_x_o);
    printf("m_y_o = %d\n", mor->m_y_o);
    printf("aspect_ratio = %f\n", mor->aspect_ratio);
}