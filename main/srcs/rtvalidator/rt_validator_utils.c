/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validator_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 05:09:38 by narin             #+#    #+#             */
/*   Updated: 2023/10/11 02:48:57 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/// @brief is a number return 1, not a number return 0
int	is_real(char *str)
{
	int		i;
	int		dot_count;
	int		len;

	i = 0;
	dot_count = 0;
	len = ft_strlen(str);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			dot_count++;
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		i++;
	}
	if (dot_count > 1 || (len == 1 && str[0] == '.') || str[len - 1] == '.')
		return (0);
	return (1);
}

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
