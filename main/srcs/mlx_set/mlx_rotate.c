/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:44:03 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/07 23:57:29 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	rotx_normal(t_vec3d *normal, double deg)
{
	t_vec3d		tem;
	t_vec3d		ret;
	double		rad;

	rad = deg * PI / 180;
	ft_memcpy(&tem, normal, sizeof(t_vec3d));
	ret.x = normal->x;
	ret.y = tem.y * cosf(rad) + tem.z * sinf(rad);
	ret.z = (-tem.y) * sinf(rad) + tem.z * cosf(rad);
	ft_memcpy(normal, &ret, sizeof(t_vec3d));
	return (SUCCESS);
}

int	roty_normal(t_vec3d *normal, double deg)
{
	t_vec3d	tem;
	t_vec3d	ret;
	double	rad;

	rad = deg * PI / 180;
	ft_memcpy(&tem, normal, sizeof(t_vec3d));
	ret.x = tem.x * cosf(rad) - tem.z * sinf(rad);
	ret.z = tem.x * sinf(rad) + tem.z * cosf(rad);
	ret.y = normal->y;
	ft_memcpy(normal, &ret, sizeof(t_vec3d));
	return (SUCCESS);
}

int	rotz_normal(t_vec3d *normal, double deg)
{
	t_vec3d	tem;
	t_vec3d	ret;
	double	rad;

	rad = deg * PI / 180;
	ft_memcpy(&tem, normal, sizeof(t_vec3d));
	ret.x = tem.x * cosf(rad) + tem.y * sinf(rad);
	ret.y = (-tem.x) * sinf(rad) + tem.y * cosf(rad);
	ret.z = normal->z;
	ft_memcpy(normal, &ret, sizeof(t_vec3d));
	return (SUCCESS);
}

int	rotate_cam(t_prog *prog, double deg)
{
	t_vec3d		*vec;
	t_camera	*cam;

	cam = (t_camera *)&prog->camera;
	vec = &cam->normal;
	if (prog->sel_axis == ACTIVE_X)
		rotx_normal(vec, deg);
	if (prog->sel_axis == ACTIVE_Y)
		roty_normal(vec, deg);
	if (prog->sel_axis == ACTIVE_Z)
		rotz_normal(vec, deg);
	init_camera(cam);
	re_render(prog);
	return (SUCCESS);
}

int	rotate_plane(t_prog *prog, double deg)
{
	t_plane		*pl;
	t_object	*obj;
	t_vec3d		*norm;

	obj = prog->cur_obj->content;
	pl = (t_plane *)obj->object;
	norm = &pl->normal;
	if (prog->sel_axis == ACTIVE_X)
		rotx_normal(norm, deg);
	if (prog->sel_axis == ACTIVE_Y)
		roty_normal(norm, deg);
	if (prog->sel_axis == ACTIVE_Z)
		rotz_normal(norm, deg);
	re_render(prog);
	return (SUCCESS);
}
