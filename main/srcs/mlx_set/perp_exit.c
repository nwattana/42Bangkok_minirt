/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perp_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:41:50 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 00:06:30 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	perp_exit(int x, t_prog *prog)
{
	t_list	*lst;

	lst = prog->obj;
	ft_lstiter(lst, clean_object_from_list);
	exit(x);
}

int	rotate_cylinder(t_prog *prog, double deg)
{
	t_cylinder	*cy;
	t_object	*obj;
	t_vec3d		*norm;

	obj = prog->cur_obj->content;
	cy = (t_cylinder *)obj->object;
	norm = &cy->normal;
	if (prog->sel_axis == ACTIVE_X)
		rotx_normal(norm, deg);
	if (prog->sel_axis == ACTIVE_Y)
		roty_normal(norm, deg);
	if (prog->sel_axis == ACTIVE_Z)
		rotz_normal(norm, deg);
	re_render(prog);
	return (SUCCESS);
}
