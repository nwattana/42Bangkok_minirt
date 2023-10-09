/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:45:58 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/10 05:22:17 by narin            ###   ########.fr       */
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
	pre_read_config(argv, &prog);
	read_rt_file(argv[1], &prog);
	// TODO REMOVE ME
	perp_exit(0, &prog);

	prog_init_mlx(&prog);
	render_image(&prog);
	ft_lstiter(prog.obj, print_object_iter);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	prog_mlx_loop(&prog);
	return (0);
}
