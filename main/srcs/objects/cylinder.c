/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:50:45 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 00:52:14 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_cylinder(void *object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object;
	printf("cylinder: \n");
	print_vec3d(&cylinder->point, "point: ");
	print_vec3d(&cylinder->normal, "normal: ");
	printf("radi: %f\n", cylinder->radi);
	printf("height: %f\n", cylinder->len);
	print_color(&cylinder->color);
}

void	clean_cylinder(void *object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object;
	free(cylinder);
}

int	cy_test_intersection(void *object, t_interparam *p)
{
	t_cylinder		*cy;
	t_object		*obj;
	t_ray			ray[3];
	t_interparam	mox[3];

	obj = (t_object *)object;
	cy = (t_cylinder *)obj->object;
	create_mox_inters(ray, mox, p);
	if (cy_rear(cy, &mox[0]))
	{
		set_inters_from_mox(p, &mox[0]);
		return (1);
	}
	if (cy_cap(cy, &mox[1]))
	{
		set_inters_from_mox(p, &mox[1]);
		return (1);
	}
	return (0);
}

void	create_mox_inters(t_ray *ray, t_interparam *mox, t_interparam *p)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		ft_memcpy(&mox[i], p, sizeof(t_interparam));
		ft_memcpy(&ray[i], p->ray, sizeof(t_ray));
		mox[i].ray = &ray[i];
		i++;
	}
}
