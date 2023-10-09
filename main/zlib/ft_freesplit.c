/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:18:24 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 03:39:13 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_split(char **split_obj)
{
	int	i;

	i = 0;
	if (!split_obj)
		return (1);
	while (split_obj[i])
	{
		free(split_obj[i]);
		i++;
	}
	free(split_obj);
	return (0);
}
