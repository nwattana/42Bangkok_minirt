/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:18:24 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/10 06:53:45 by narin            ###   ########.fr       */
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
