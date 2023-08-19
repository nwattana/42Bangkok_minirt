/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:06:10 by lsomrat           #+#    #+#             */
/*   Updated: 2022/03/12 10:28:25 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*add_str(char const *s, int n)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *) malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		n;
	char	**ptr;

	if (!s)
		return (NULL);
	i = 0;
	n = 0;
	start = 0;
	ptr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (s[n])
	{
		if (s[n] != c && n > 0 && s[n - 1] == c)
			start = n;
		if (s[n] == c && n > 0 && s[n - 1] != c)
			ptr[i++] = add_str(&s[start], n - start);
		else if (!s[n + 1] && s[n] != c)
			ptr[i++] = add_str(&s[start], n - start + 1);
		n++;
	}
	ptr[i] = 0;
	return (ptr);
}
