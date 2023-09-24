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
	prog_init_mlx(&prog);

	// prog state update geometry
	prog.p_state = P_STATE_CAM_GEOMETRY;

	t_camera *cam;
	t_object *obj;

	obj = (t_object *)get_object_from_list(prog.obj, CAMERA);
	obj->print(obj->object);

	// Generate image
	render_image(&prog);

	// ft_lstiter(prog.obj, print_object_iter);
	ft_lstclear(&(prog.obj), clean_object_from_list);

	// // // TODO: change me
	t_mlx_confix *vars;
	vars = &(prog.mlx_config);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	
	
	// // FIXME: Segmentaion fault what is wrong?
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

