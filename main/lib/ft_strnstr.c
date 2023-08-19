/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 23:26:59 by lsomrat           #+#    #+#             */
/*   Updated: 2022/02/28 01:01:58 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (needle == haystack || *needle == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && nlen <= len--)
	{
		if (!(ft_strncmp((char *)haystack, (char *)needle, nlen)))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
