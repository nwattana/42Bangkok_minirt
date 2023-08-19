/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:20:01 by lsomrat           #+#    #+#             */
/*   Updated: 2022/03/13 14:36:27 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	if (dstsize == 0)
		return (ft_strlen(src));
	srcsize = 0;
	while (src[srcsize] && srcsize < dstsize - 1)
	{
		dst[srcsize] = src[srcsize];
		srcsize++;
	}
	dst[srcsize] = '\0';
	return (ft_strlen(src));
}
