/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:22:58 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 03:36:07 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file_fd(int fd, char *g_buffer)
{
	char	*r_buffer;
	char	*temp;
	int		byte_read;

	if (!g_buffer)
		g_buffer = ft_calloc(1, 1);
	r_buffer = (char *)ft_calloc(sizeof(char), 1);
	if (!r_buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, r_buffer, 1);
		if (byte_read > 0)
		{
			temp = g_buffer;
			g_buffer = ft_strjoinn(g_buffer, r_buffer, byte_read);
			free (temp);
		}
		if (ft_strchr(g_buffer, '\n') || !g_buffer)
			break ;
	}
	free(r_buffer);
	r_buffer = NULL;
	return (g_buffer);
}

char	*get_line(char *para)
{
	char	*line;
	char	*n_loc;

	if (!para)
		return (NULL);
	n_loc = ft_strchr(para, '\n');
	if (n_loc)
		line = ft_substrr(para, 0, n_loc - para + 1);
	else if (ft_strlen(para) > 0)
		line = ft_substr(para, 0, ft_strlen(para));
	else
		line = NULL;
	return (line);
}

char	*update_g(char *g_buffer, char *line)
{
	char	*res;
	int		len_line;
	int		i;

	i = 0;
	if (!line)
	{
		if (g_buffer)
			free(g_buffer);
		g_buffer = NULL;
		return (NULL);
	}
	len_line = ft_strlen(line);
	res = (char *)ft_calloc(sizeof(char), ft_strlen(g_buffer) - len_line + 1);
	if (!res)
		return (NULL);
	while (*(g_buffer + len_line + i))
	{
		*(res + i) = *(g_buffer + len_line + i);
		i++;
	}
	free(g_buffer);
	g_buffer = NULL;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*g_buffer;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		if (g_buffer != NULL)
			free(g_buffer);
		return (NULL);
	}
	g_buffer = read_file_fd(fd, g_buffer);
	line = get_line(g_buffer);
	g_buffer = update_g(g_buffer, line);
	return (line);
}
