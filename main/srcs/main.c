#include "../inc/minirt.h"

void debug_mlx_status(t_mlx_confix *vars)
{
	printf("is_initmlx: %d\n", vars->is_initmlx);
	printf("is_initwin: %d\n", vars->is_initwin);
	printf("is_init_img: %d\n", vars->is_init_img);
}

int	main(int argc, char **argv)
{
	t_prog	prog;

	prog_constructor(&prog);
	
	if (validate_args(argc, argv, &prog))
	{
		return (1);
	}
	// parsing input
	read_rt_file(argv[1], &prog);
	printf("prog state: %d\n", prog.p_state);

	// Create MLX window and image
	// prog_init_mlx(&prog);

	// Generate image
	// render_image(&prog);

	ft_lstiter(prog.obj, print_object_iter);
	ft_lstclear(&(prog.obj), clean_object_from_list);

	// // TODO: change me
	// t_mlx_confix *vars;
	// vars = &(prog.mlx_config);
    // mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	// // FIXME: Segmentaion fault what is wrong?
    // mlx_my_loop(vars);
	return (0);
}

void	prog_init_mlx(t_prog *prog)
{
	t_mlx_confix	*mlx_config;

	mlx_config = &(prog->mlx_config);
	mlx_my_init(mlx_config);

	// MORE setting up mlx
}

void	render_image(t_prog *prog)
{
	int		win_x;
	int		win_y;
	int		color;

	win_x = 0;
	while (win_x < WINDOW_WIDTH)
	{
		win_y = 0;
		while (win_y < WINDOW_HEIGHT)
		{
			// all render logic here
			color = gen_color_xy(win_x, win_y, prog);
			
			mlx_my_putpixel(&(prog->mlx_config.img), win_x, win_y, color);
			win_y++;
		}
		win_x++;
	}
}

int gen_color_xy(int win_x, int win_y, t_prog *prog)
{
	int	color;
	double r;
	double g;
	double b;

	r = ((double)win_x / (double)WINDOW_WIDTH) * 255.0;
	g = ((double)win_y / (double)WINDOW_HEIGHT) * 255.0;
	color = create_rgb(r, g, 0);

	return (color);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
