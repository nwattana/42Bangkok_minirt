/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validator_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 05:09:38 by narin             #+#    #+#             */
/*   Updated: 2023/10/14 02:03:14 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/// @brief is 0,0,0, valid return 0, invalid return 1
int	is_3d_realnum(char *str)
{
	char	**splited;

	if (!str)
	{
		debug_message("is_3d_realnum: str is NULL passed");
		return (1);
	}
	splited = ft_split(str, ',');
	if (count_splited(splited) != 3)
	{
		debug_message("is_3d_realnum: count_splited != 3");
		return (0);
	}
	if (!is_real(splited[0]) || !is_real(splited[1]) || !is_real(splited[2]))
	{
		return (0);
	}
	ft_free_split(splited);
	return (1);
}

/// @brief Counting the number of elements in a string array
size_t	count_splited(char **splited)
{
	size_t	i;

	if (!splited)
	{
		debug_message("ERROR: splited is NULL");
		return (0);
	}
	i = 0;
	while (splited[i])
		i++;
	return (i);
}
