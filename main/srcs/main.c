#include "../inc/minirt.h"

void debug_mlx_status(t_mlx_confix *vars)
{
	printf("is_initmlx: %d\n", vars->is_initmlx);
	printf("is_initwin: %d\n", vars->is_initwin);
	printf("is_init_img: %d\n", vars->is_init_img);
}

void error_exit(char *msg)
{
	printf("%s", msg);
	exit(1);
}

int validate_args(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
		error_exit("Error\nNo arguments\n");
	if (argc != 2)
		error_exit("Error\nToo many arguments\n");
	
	return (0);
}

int	main(int argc, char **argv)
{
	// t_prog	program;

	// FUNC
	validate_args(argc, argv);
	double x;

	ft_strtod("123.456", &x);
	printf("%f\n", x);


	return (0);
}
