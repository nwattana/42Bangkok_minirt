/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:55:15 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/14 16:45:20 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_plane(void *pl)
{
	t_plane	*plane;

	plane = (t_plane *)pl;
	printf(H_LINE);
	printf("Plane:\n");
	printf("  plane point:  %f, %f, %f\n", \
		plane->point.x, plane->point.y, plane->point.z);
	printf("  plane normal: %f, %f, %f\n", \
		plane->normal.x, plane->normal.y, plane->normal.z);
	printf("  plane color:  %d, %d, %d\n", \
		plane->color.r, plane->color.g, plane->color.b);
	printf(H_LINE);
}

void	clean_plane(void *pl)
{
	t_plane	*plane;

	plane = (t_plane *)pl;
	free(plane);
}

int	pl_test_intersection(void *object, t_interparam *param)
{
	t_plane		*plane;
	t_object	*obj;

	obj = (t_object *)object;
	plane = (t_plane *)obj->object;
	return (pl_sub_intersect(plane, param));
}

int	pl_sub_intersect(t_plane *plane, t_interparam *param)
{
	double	dist;
	t_vec3d	*ray;

	ray = &param->ray->direction;
	dist = pl_cale_dist(param->ray, plane, &param->f_ishit, param);
	if (dist > 0)
	{
		param->f_color = plane->color;
		param->f_dist = dist;
		param->f_point.x = param->ray->origin.x + dist * ray->x;
		param->f_point.y = param->ray->origin.y + dist * ray->y;
		param->f_point.z = param->ray->origin.z + dist * ray->z;
		ft_memcpy(&param->f_normal, &plane->normal, sizeof(t_vec3d));
		param->f_ishit = 1;
	}
	return (param->f_ishit);
}
