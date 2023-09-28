#include "../inc/minirt.h"

void debug_mlx_status(t_mlx_confix *vars)
{
	printf("is_initmlx: %d\n", vars->is_initmlx);
	printf("is_initwin: %d\n", vars->is_initwin);
	printf("is_init_img: %d\n", vars->is_init_img);
}

int	main(int argc, char **argv)
{
	// t_prog	prog;

	// prog_constructor(&prog);
	
	// if (validate_args(argc, argv, &prog))
	// {
	// 	return (1);
	// }

	// // parsing input
	// read_rt_file(argv[1], &prog);
	// printf("prog state: %d\n", prog.p_state);

	// // Create MLX window and image
	// prog_init_mlx(&prog);

	// // prog state update geometry
	// prog.p_state = P_STATE_CAM_GEOMETRY;

	// // Generate image
	// render_image(&prog);

	// // ft_lstiter(prog.obj, print_object_iter);
	// ft_lstclear(&(prog.obj), clean_object_from_list);

	// // // // TODO: change me
	// t_mlx_confix *vars;
	// vars = &(prog.mlx_config);

	// // // FIXME: Segmentaion fault what is wrong?
    // mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
    // prog_mlx_loop(&prog);

	t_tfmat tfmat;
	t_vec3d translete;
	t_vec3d rotate_x;
	t_vec3d rotate_y;
	t_vec3d rotate_z;
	t_vec3d scale;
	t_mat33 rot;
	double len;

	vec3d_init(&translete, 1, 2, 3);
	vec3d_init(&rotate_x, 0.4, 0, 0);
	vec3d_init(&rotate_y, 0, 0.5, 0);
	vec3d_init(&rotate_z, 0, 0, 0.5);
	vec3d_init(&scale, 2, 2, 2);
	vector_to_translation(&(tfmat.translate), &translete);
	vector_to_rotate_x(&(tfmat.rotate_x), &rotate_x);
	vector_to_rotate_y(&(tfmat.rotate_y), &rotate_y);
	vector_to_rotate_z(&(tfmat.rotate_z), &rotate_z);
	vector_to_scale_matrix(&(tfmat.scale_metrix), &scale);
	mul_tf_member(&tfmat);
	// print_tfmat(&tfmat);
	test_minor(&(tfmat.mul));



	return (0);
}

void	prog_init_mlx(t_prog *prog)
{
	t_mlx_confix	*mlx_config;

	mlx_config = &(prog->mlx_config);
	mlx_my_init(mlx_config);
	// MORE setting up mlx
}
