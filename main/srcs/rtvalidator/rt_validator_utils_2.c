/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validator_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 02:48:32 by narin             #+#    #+#             */
/*   Updated: 2023/10/11 02:52:46 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/// @brief compare till end of string
int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
	{
		return (0);
	}
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	free_set_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	is_rgb3d(t_vec3d *vec)
{
	if (vec->x < 0 || vec->y < 0 || vec->z < 0 \
		|| vec->x > 255 || vec->y > 255 || vec->z > 255)
		return (0);
	return (1);
}

void	init_inst_counter(t_inst_counter *ins)
{
	ins->camera_count = 0;
	ins->light_count = 0;
	ins->object_count = 0;
	ins->amb_light_count = 0;
}

int	strreplace_space(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r')
			str[i] = ' ';
		i++;
	}
	return (0);
}
