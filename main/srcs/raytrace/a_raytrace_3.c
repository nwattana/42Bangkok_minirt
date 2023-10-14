/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_raytrace_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 03:34:36 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/14 17:58:33 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	gather_inters_info(t_interparam *param, t_object *focus_obj)
{
	param->inters_dist = param->f_dist;
	ft_memcpy(&param->inters_point, &param->f_point, sizeof(t_vec3d));
	ft_memcpy(&param->inters_normal, &param->f_normal, sizeof(t_vec3d));
	ft_memcpy(&param->inters_color, &param->f_color, sizeof(t_color));
	param->inters_obj_id = focus_obj->id;
	param->d_inters_obj_type = focus_obj->type;
	return (SUCCESS);
}

int	init_intersection_param(t_prog *prog, t_ray *ray, t_interparam *param)
{
	(void)prog;
	(void)ray;
	reset_inters_focus(param);
	vec3d_init(&param->inters_normal, 0, 0, 0);
	vec3d_init(&param->inters_point, 0, 0, 0);
	param->inters_dist = INFINITY;
	param->f_ishit = 0;
	param->inters_obj_id = -1;
	param->inters_color = (t_color){0, 0, 0};
	param->start_ray_obj_id = CAMERA_ID;
	param->hit = 1;
	param->f_ishit = 0;
	return (SUCCESS);
}

int	reset_inters_focus(t_interparam *param)
{
	param->f_dist = INFINITY;
	param->f_ishit = 0;
	param->f_color = (t_color){0, 0, 0};
	return (SUCCESS);
}

void	print_obj_type(int type)
{
	if (type == SPHERE)
		ft_putstr_fd("SPHERE", 1);
	else if (type == PLANE)
		ft_putstr_fd("PLANE", 1);
	else if (type == CYLINDER)
		ft_putstr_fd("CYLINDER", 1);
	else if (type == CAMERA)
		ft_putstr_fd(GREEN"CAMERA"CLOSE, 1);
}
