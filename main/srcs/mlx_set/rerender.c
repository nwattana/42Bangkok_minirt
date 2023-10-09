/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:33:32 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 03:50:01 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	re_render(t_prog *prog)
{
	t_mlx_confix	*vars;

	render_image(prog);
	vars = &(prog->mlx_config);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (SUCCESS);
}
