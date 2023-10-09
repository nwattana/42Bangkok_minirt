/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_rt_validatot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:49:32 by narin             #+#    #+#             */
/*   Updated: 2023/10/10 05:07:02 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	debug_inst_counter(t_inst_counter *ins)
{
	printf("camera_count = %d\n", ins->camera_count);
	printf("light_count = %d\n", ins->light_count);
	printf("object_count = %d\n", ins->object_count);
	printf("amb_light_count = %d\n", ins->amb_light_count);
	return (0);
}
