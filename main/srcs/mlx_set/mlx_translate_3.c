/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_translate_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:48:03 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/14 05:17:54 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	cy_minus_trans(t_prog *prog)
{
	t_cylinder	*cy;
	t_object	*obj;

	obj = prog->cur_obj->content;
	cy = (t_cylinder *)obj->object;
	if (prog->sel_axis == ACTIVE_X)
		cy->point.x -= 1;
	if (prog->sel_axis == ACTIVE_Y)
		cy->point.y -= 1;
	if (prog->sel_axis == ACTIVE_Z)
		cy->point.z -= 1;
	re_render(prog);
	return (SUCCESS);
}

int	pl_minus_trans(t_prog *prog)
{
	t_plane		*pl;
	t_object	*obj;

	obj = prog->cur_obj->content;
	pl = (t_plane *)obj->object;
	if (prog->sel_axis == ACTIVE_X)
		pl->point.x -= 1;
	if (prog->sel_axis == ACTIVE_Y)
		pl->point.y -= 1;
	if (prog->sel_axis == ACTIVE_Z)
		pl->point.z -= 1;
	re_render(prog);
	return (SUCCESS);
}

int	pl_plus_trans(t_prog *prog)
{
	t_plane		*pl;
	t_object	*obj;

	obj = prog->cur_obj->content;
	pl = (t_plane *)obj->object;
	if (prog->sel_axis == ACTIVE_X)
		pl->point.x += 1;
	if (prog->sel_axis == ACTIVE_Y)
		pl->point.y += 1;
	if (prog->sel_axis == ACTIVE_Z)
		pl->point.z += 1;
	re_render(prog);
	return (SUCCESS);
}
