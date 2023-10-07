/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:18:09 by lsomrat           #+#    #+#             */
/*   Updated: 2023/10/08 02:11:50 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	cy_rear(t_cylinder *cy, t_interparam *p)
{
	double	dist;
	t_vec3d	ints2point;

	dist = cy_cale_dist(p->ray, cy);
	if (dist > 0.0)
	{
		cy_intersection_point(&p->f_point, p->ray, dist);
		cy_intersection_normal(&p->f_normal, &p->f_point, &cy->point);
		vec3d_minus(&ints2point, &p->f_point, &cy->point);
		if (fabs(vec3d_dot(&ints2point, &cy->normal)) < cy->len / 2.0)
		{
			p->f_dist = dist;
			p->f_ishit = 1;
			ft_memcpy(&p->f_color, &cy->color, sizeof(t_color));
			return (1);
		}
	}
	return (0);
}

int	set_inters_from_mox(t_interparam *p, t_interparam *mox)
{
	p->f_dist = mox->f_dist;
	p->f_ishit = mox->f_ishit;
	ft_memcpy(&p->f_color, &mox->f_color, sizeof(t_color));
	ft_memcpy(&p->f_point, &mox->f_point, sizeof(t_vec3d));
	ft_memcpy(&p->f_normal, &mox->f_normal, sizeof(t_vec3d));
	return (SUCCESS);
}

int	cy_cap(t_cylinder *cy, t_interparam *p)
{
	t_vec3d	inters2center;
	t_plane	pl[2];

	cy_create_plane(pl, cy);
	if (pl_sub_intersect(&pl[0], p))
	{
		vec3d_minus(&inters2center, &p->f_point, &pl[0].point);
		if (vec3d_length(&inters2center) < cy->radi)
		{
			p->f_dist = p->f_dist;
			p->f_ishit = 1;
			ft_memcpy(&p->f_color, &cy->color, sizeof(t_color));
			return (1);
		}
	}
	if (pl_sub_intersect(&pl[1], p))
	{
		vec3d_minus(&inters2center, &p->f_point, &pl[1].point);
		if (vec3d_length(&inters2center) < cy->radi)
		{
			p->f_dist = p->f_dist;
			p->f_ishit = 1;
			ft_memcpy(&p->f_color, &cy->color, sizeof(t_color));
			return (1);
		}
	}
	return (0);
}

int	cy_intersection_normal(t_vec3d *norm, t_vec3d *inters, t_vec3d *cent)
{
	vec3d_minus(norm, inters, cent);
	if (vec3d_normalize(norm))
	{
		debug_message("cyhere intersection_normal: normal is zero vector\n");
		return (ERROR);
	}
	return (SUCCESS);
}
