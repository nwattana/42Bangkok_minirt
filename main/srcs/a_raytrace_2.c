/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_raytrace_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 03:25:22 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 03:34:27 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	trace_light(t_prog *prog, t_interparam *param)
{
	t_obslight	l_param;

	init_inters_light_param(prog, param, &l_param);
	if (param == NULL)
	{
		printf("trace_light: param is NULL\n");
		exit(0);
	}
	trace_inters_to_light(prog, param, &l_param);
	if (l_param.stuck == 0)
		cale_angle_scale(&l_param, param);
	color_scale(&l_param.light.light_color, \
		l_param.angle_scale, &param->inters_color);
	color_scale(&l_param.light.ambient_color, \
		prog->ambient_intensity, &param->inters_color);
	color_plus(&param->final_color, \
		&l_param.light.ambient_color, &l_param.light.light_color);
}

void	init_inters_light_param(t_prog *prog, \
	t_interparam *param, t_obslight *light_param)
{
	color_set_defval(&light_param->light.light_color);
	color_set_defval(&light_param->light.ambient_color);
	light_param->scale_angle = 0;
	light_param->angle = 0;
	vec3d_minus(&light_param->light_dir, \
		&prog->light.position, &param->inters_point);
	light_param->max_dist = vec3d_length(&light_param->light_dir);
	vec3d_normalize(&light_param->light_dir);
	light_param->stuck = 0;
	vec3d_assign(&light_param->ray.origin, &param->inters_point);
	vec3d_assign(&light_param->ray.direction, &light_param->light_dir);
	param->ray = &light_param->ray;
}

int	trace_inters_to_light(t_prog *prog, \
	t_interparam *param, t_obslight *light_param)
{
	t_list		*lst;
	t_object	*obj;
	int			temp;

	lst = prog->obj;
	temp = 0;
	while (lst && !temp)
	{
		reset_inters_focus(param);
		obj = (t_object *)lst->content;
		if (obj->id == param->inters_obj_id)
		{
			lst = lst->next;
			continue ;
		}
		temp = if_intersec(obj, param);
		lst = lst->next;
	}
	if (param->f_dist < light_param->max_dist - 0.001)
		light_param->stuck = 1;
	return (temp);
}

int	if_intersec(t_object *obj, t_interparam *param)
{
	int	temp;

	temp = 0;
	if (obj->type == SPHERE)
		temp = sp_test_intersection(obj, param);
	else if (obj->type == PLANE)
		temp = pl_test_intersection(obj, param);
	else if (obj->type == CYLINDER)
		temp = cy_test_intersection(obj, param);
	return (temp);
}

int	trace_ray_to_obj(t_prog *prog, t_interparam *param)
{
	t_list		*lst;
	t_object	*focus_obj;
	int			f_hit;

	lst = prog->obj;
	while (lst)
	{
		reset_inters_focus(param);
		focus_obj = (t_object *)lst->content;
		if (focus_obj->type == SPHERE)
			f_hit = sp_test_intersection(focus_obj, param);
		else if (focus_obj->type == PLANE)
			f_hit = pl_test_intersection(focus_obj, param);
		else if (focus_obj->type == CYLINDER)
			f_hit = cy_test_intersection(focus_obj, param);
		if (param->f_ishit == 1)
			if (param->f_dist < param->inters_dist)
				gather_inters_info(param, focus_obj);
		lst = lst->next;
	}
	return (param->hit);
}
