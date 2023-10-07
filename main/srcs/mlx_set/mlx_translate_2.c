/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_translate_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:44:46 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/07 23:49:49 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	select_active_axis(t_prog *prog, int kc)
{
	debug_message("SELECT ACTIVE AXIS\n");
	prog->sel_axis = kc;
	return (SUCCESS);
}

int	minus_axis(t_prog *prog)
{
	if (prog->sel_type == CAMERA)
		camera_translate_minus(prog);
	if (prog->sel_type == SPHERE)
		sp_minus_trans(prog);
	if (prog->sel_type == PLANE)
		pl_minus_trans(prog);
	if (prog->sel_type == CYLINDER)
		cy_minus_trans(prog);
	return (SUCCESS);
}

int	plus_axis(t_prog *prog)
{
	if (prog->sel_type == CAMERA)
		camera_translate_add(prog);
	if (prog->sel_type == SPHERE)
		sp_plus_trans(prog);
	if (prog->sel_type == PLANE)
		pl_plus_trans(prog);
	if (prog->sel_type == CYLINDER)
		cy_minus_trans(prog);
	return (SUCCESS);
}

int	cy_plus_trans(t_prog *prog)
{
	t_cylinder	*cy;
	t_object	*obj;

	obj = prog->cur_obj->content;
	cy = (t_cylinder *)obj->object;
	if (prog->sel_axis == ACTIVE_X)
		cy->point.x += 1;
	if (prog->sel_axis == ACTIVE_Y)
		cy->point.y += 1;
	if (prog->sel_axis == ACTIVE_Z)
		cy->point.z += 1;
	re_render(prog);
	return (SUCCESS);
}
