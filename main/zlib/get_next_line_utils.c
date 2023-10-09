/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:36:48 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 03:36:03 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinn(char *head, char *tail, int byte_read)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *)ft_calloc(sizeof(char), \
			(ft_strlen(head) + ft_strlen(tail) + 1));
	if (!res)
		return (NULL);
	while (head[i])
	{
		res[i] = head[i];
		i++;
	}
	while (tail[j] && byte_read--)
	{
		res[i + j] = tail[j];
		j++;
	}
	return (res);
}

char	*ft_strchrr(const char *s, int c)
{
	char	*temp;

	if (!s)
		return (NULL);
	temp = (char *)s;
	while (*temp)
	{
		if (*temp == c)
			return (temp);
		temp++;
	}
	return (NULL);
}

char	*ft_substrr(const char *s, int start, int len)
{
	char	*res;
	int		i;

	i = 0;
	if (len < 0 || !s || start < 0)
		return (NULL);
	res = (char *)ft_calloc(sizeof(char), len + 1);
	while (*(s + start + i) != '\0' && i < len)
	{
		res[i] = *(s + start + i);
		i++;
	}
	return (res);
}
