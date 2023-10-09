/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:53:45 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 02:18:10 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_sphere(void *sph)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)sph;
	printf(H_LINE);
	printf("Sphere: %f\n", sphere->radius);
	printf("  sphere center: %f, %f, %f\n", \
		sphere->center.x, sphere->center.y, sphere->center.z);
	printf("  sphere color:  %d, %d, %d\n", \
		sphere->color.r, sphere->color.g, sphere->color.b);
	printf("  sphere radius: %f\n", sphere->radius);
	printf(H_LINE);
}

void	clean_sphere(void *sph)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)sph;
	free(sphere);
}

int	sp_test_intersection(void *object, t_interparam *p)
{
	double		dist;
	t_sphere	*sp;
	t_object	*obj;
	t_vec3d		out_vec;

	obj = (t_object *)object;
	sp = (t_sphere *)obj->object;
	dist = sp_cale_dist(p->ray, sp);
	if (dist > 0.0)
	{
		p->f_dist = dist;
		p->f_ishit = 1;
		sp_intersection_point(&p->f_point, p->ray, dist);
		sp_intersection_normal(&p->f_normal, &p->f_point, &sp->center);
		ft_memcpy(&p->f_color, &sp->color, sizeof(t_color));
	}
	return (p->f_ishit);
}

int	sp_intersection_normal(t_vec3d *normal, \
	t_vec3d *inters, t_vec3d *center)
{
	vec3d_minus(normal, inters, center);
	if (vec3d_normalize(normal))
	{
		debug_message("sphere intersection_normal: normal is zero vector\n");
		return (ERROR);
	}
	return (SUCCESS);
}
