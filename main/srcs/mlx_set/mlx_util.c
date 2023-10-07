#include "../../inc/minirt.h"

void    mlx_my_init(t_mlx_confix *vars)
{
    vars->mlx = mlx_init();
    vars->is_initmlx = 1;
    vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, PROGRAM_NAME);
    vars->is_initwin = 1;
    vars->img.img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, &vars->img.width, &vars->img.endian);
    fill_image_with_color(vars);
    vars->is_init_img = 1;
}

int close_window(void)
{
    exit(0);
}

void prog_mlx_loop(t_prog *prog)
{
    t_mlx_confix *vars;

    prog->selected_obj = &prog->camera;
    prog->sel_type = CAMERA;
    prog->sel_axis = ACTIVE_X;
    vars = &(prog->mlx_config);
    mlx_hook(vars->win, 17, 0, close_window, vars);
    mlx_hook(vars->win, 2, 1L << 0, &keyhandler, prog);
    mlx_loop(vars->mlx);
}

void debug_mlx_status(t_mlx_confix *vars)
{
	printf("is_initmlx: %d\n", vars->is_initmlx);
	printf("is_initwin: %d\n", vars->is_initwin);
	printf("is_init_img: %d\n", vars->is_init_img);
}