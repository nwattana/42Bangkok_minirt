#include "../inc/minirt.h"

void debug_mlx_status(t_mlx_confix *vars)
{
    printf("is_initmlx: %d\n", vars->is_initmlx);
    printf("is_initwin: %d\n", vars->is_initwin);
    printf("is_init_img: %d\n", vars->is_init_img);
}

void terror(char *str)
{
    ft_putstr_fd(str, 2);
    exit(1);
}

int	main(int argc, char **argv)
{
    t_color a_bicolor = {255, 255, 255};
    t_ambient ambient = {0.2, 255, 255, 255};
    t_camera camera = {{0, 0, 0}, {0, 0, 1}, 90};
    t_sphere sphere = {{0, 0, 10.6}, 12.6, 10, 0, 255};

    t_mlx_confix vars;

    init_my_mlx(&vars);
	int i = -1;

	while (++i < WINDOW_WIDTH / 4)
    {
		ppixel(&vars, i, 0, 0xff00ff);
		ppixel(&vars, -i, 0, 0xff00ff);
    }
	i = -1;
	while (++i < WINDOW_HEIGHT / 4)
    {
        printf("i=%d\n", i);
		ppixel(&vars, 0, i, 0xff00ff);
		ppixel(&vars, 0, -i, 0xff00ff);
    }

    int pixel_screen_x;
    int pixel_screen_y;




    mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
    mlx_my_loop(&vars);
    return (0);
}
