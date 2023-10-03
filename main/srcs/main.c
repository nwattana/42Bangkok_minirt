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

	// Generate image
	render_image(&prog);


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


int		mul_mat_to_vector(t_vec3d *res, t_tfmat *mat, t_vec3d *in_vec, int dir)
{
	t_mat44		*tmp;
	
	if (dir == 1)
		tmp = &(mat->fwd);
	else
		tmp = &(mat->bwd);
	res->x = tmp->m44[0][0] * in_vec->x + tmp->m44[0][1] * \
		in_vec->y + tmp->m44[0][2] * in_vec->z + tmp->m44[0][3];
	res->y = tmp->m44[1][0] * in_vec->x + tmp->m44[1][1] * \
		in_vec->y + tmp->m44[1][2] * in_vec->z + tmp->m44[1][3];
	res->z = tmp->m44[2][0] * in_vec->x + tmp->m44[2][1] * \
		in_vec->y + tmp->m44[2][2] * in_vec->z + tmp->m44[2][3];

	return (0);
}


/// @brief Apply transformation matrix to ray
/// @param res 
/// @param mat 
/// @param in_ray 
/// @param dir 
/// @return 
int		apply_tfmat_to_ray(t_ray *res, t_tfmat *mat, t_ray *in_ray, int dir)
{
	mul_mat_to_vector(&(res->origin), mat, &(in_ray->origin), dir);
	mul_mat_to_vector(&(res->destination), mat, &(in_ray->destination), dir);
	vec3d_minus(&(res->direction), &(res->destination), &(res->origin));
	vec3d_normalize(&(res->direction));

	return (0);
}

int		apply_tfmat_to_vec(t_vec3d *res, t_tfmat *mat, t_vec3d *in_vec, int dir)
{
	mul_mat_to_vector(res, mat, in_vec, dir);
	return (0);
}