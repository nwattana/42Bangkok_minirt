/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:52:35 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 01:03:58 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_light(void *lg)
{
	t_light	*light;

	light = (t_light *)lg;
	printf(H_LINE);
	printf("Light:\n");
	printf("  light position: %f, %f, %f\n", \
		light->position.x, light->position.y, light->position.z);
	printf("  light intensity: %f\n", \
		light->intensity);
	printf("  light color:   %d, %d, %d\n", \
		light->color.r, light->color.g, light->color.b);
	printf(H_LINE);
}

void	clean_light(void *lg)
{
	t_light	*light;

	light = (t_light *)lg;
	free(light);
}
