/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:36:31 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/07 23:49:12 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	camera_translate_minus(t_prog *prog)
{
	t_camera	*cam;

	cam = (t_camera *)prog->selected_obj;
	if (prog->sel_axis == ACTIVE_X)
		cam->position.x -= 1;
	if (prog->sel_axis == ACTIVE_Y)
		cam->position.y -= 1;
	if (prog->sel_axis == ACTIVE_Z)
		cam->position.z -= 1;
	re_render(prog);
	return (SUCCESS);
}

int	camera_translate_add(t_prog *prog)
{
	t_camera	*cam;

	cam = (t_camera *)prog->selected_obj;
	if (prog->sel_axis == ACTIVE_X)
		cam->position.x += 1;
	if (prog->sel_axis == ACTIVE_Y)
		cam->position.y += 1;
	if (prog->sel_axis == ACTIVE_Z)
		cam->position.z += 1;
	re_render(prog);
	return (SUCCESS);
}

int	sp_plus_trans(t_prog *prog)
{
	t_sphere	*sp;
	t_object	*obj;

	obj = prog->cur_obj->content;
	sp = (t_sphere *)obj->object;
	if (prog->sel_axis == ACTIVE_X)
		sp->center.x += 1;
	if (prog->sel_axis == ACTIVE_Y)
		sp->center.y += 1;
	if (prog->sel_axis == ACTIVE_Z)
		sp->center.z += 1;
	re_render(prog);
	return (SUCCESS);
}

int	sp_minus_trans(t_prog *prog)
{
	t_sphere	*sp;
	t_object	*obj;

	obj = prog->cur_obj->content;
	sp = (t_sphere *)obj->object;
	if (prog->sel_axis == ACTIVE_X)
		sp->center.x -= 1;
	if (prog->sel_axis == ACTIVE_Y)
		sp->center.y -= 1;
	if (prog->sel_axis == ACTIVE_Z)
		sp->center.z -= 1;
	re_render(prog);
	return (SUCCESS);
}
