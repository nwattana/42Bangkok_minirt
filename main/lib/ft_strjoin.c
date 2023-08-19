/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:55:34 by lsomrat           #+#    #+#             */
/*   Updated: 2022/03/09 14:22:46 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		size1;
	int		size2;
	char	*str;

	if (s1 && s2)
	{
		size1 = ft_strlen(s1);
		size2 = ft_strlen(s2);
		str = (char *) malloc(sizeof(char) * (size1 + size2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[size1] = s2[i];
			size1++;
		}
		str[size1] = '\0';
		return (str);
	}
	return (NULL);
}
