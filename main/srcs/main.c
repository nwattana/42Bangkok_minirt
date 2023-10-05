#include "../inc/minirt.h"

int	main(int argc, char **argv)
{
	t_prog	prog;

	prog_constructor(&prog);
	if (validate_args(argc, argv, &prog))
	{
		ft_putstr_fd("Error\n",2);
		return (1);
	}
	// parsing input
	read_rt_file(argv[1], &prog);

	// Create MLX window and image
	prog_init_mlx(&prog);

	// Generate image
	// render_image(&prog);

	// // TODO: change me
	t_mlx_confix *vars;
	vars = &(prog.mlx_config);

	// // FIXME: Segmentaion fault what is wrong?
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	
    prog_mlx_loop(&prog);
	return (0);
}



void	prog_init_mlx(t_prog *prog)
{
	t_mlx_confix	*mlx_config;

	mlx_config = &(prog->mlx_config);
	mlx_my_init(mlx_config);
	// MORE setting up mlx
}
