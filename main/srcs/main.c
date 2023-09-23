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
	printf("prog state: %d\n", prog.p_state);
	
	if (validate_args(argc, argv, &prog))
	{
		return (1);
	}
	// parsing input
	read_rt_file(argv[1], &prog);
	printf("prog state: %d\n", prog.p_state);

	t_list *lst;

	lst = prog.obj;
	print_object_from_list(lst);


	// init mlx vars
    // t_mlx_confix vars;
    // mlx_my_init(&vars);
    // mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
    // mlx_my_loop(&vars);

	return (0);
}
