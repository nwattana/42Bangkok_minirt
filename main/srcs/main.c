/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:45:58 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 02:47:55 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int argc, char **argv)
{
	t_prog			prog;
	t_mlx_confix	*vars;

	vars = &(prog.mlx_config);
	prog_constructor(&prog);
	if (validate_args(argc, argv, &prog))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	read_rt_file(argv[1], &prog);
	prog_init_mlx(&prog);
	render_image(&prog);
	ft_lstiter(prog.obj, print_object_iter);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	prog_mlx_loop(&prog);
	return (0);
}

void	prog_init_mlx(t_prog *prog)
{
	t_mlx_confix	*mlx_config;

	mlx_config = &(prog->mlx_config);
	mlx_my_init(mlx_config);
}
