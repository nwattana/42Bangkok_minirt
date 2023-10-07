/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:31:34 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/07 23:32:05 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	vec3d_tonormal(t_vec3d *res, t_vec3d *in)
{
	double	length;

	if (in == NULL || res == NULL)
		return (ERROR);
	length = vec3d_length(in);
	if (length == 0)
	{
		debug_message("vec3d_tonormal: length is 0");
		return (ERROR);
	}
	res->x = in->x / length;
	res->y = in->y / length;
	res->z = in->z / length;
	return (SUCCESS);
}
