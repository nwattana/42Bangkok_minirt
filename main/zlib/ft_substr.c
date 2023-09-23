/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:52:53 by lsomrat           #+#    #+#             */
/*   Updated: 2022/03/03 10:33:05 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t		slen;
	size_t		i;
	char		*dest;

	slen = ft_strlen(s);
	if (start > slen)
	{
		dest = (char *) malloc(sizeof(char));
		dest[0] = '\0';
		return (dest);
	}
	if (slen < len)
		dest = (char *) malloc(sizeof(char) * (slen - start + 1));
	else
		dest = (char *) malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
