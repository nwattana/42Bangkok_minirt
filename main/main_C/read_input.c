/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 01:02:15 by lsomrat           #+#    #+#             */
/*   Updated: 2023/08/21 01:02:17 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	*get_input(char **data, char *file)
{
	char	*str;
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_file("Error\n file not found");
	*data = ft_calloc(1, sizeof(char *));
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		str = *data;
		*data = ft_strjoin(str, temp);
		free(temp);
		free(str);
	}
	close(fd);
	return (*data);
}

int	check_fextension(char *file)
{
	int		len;
	char	*str;

	len = ft_strlen(file);
	if (len < 3)
		return (0);
	str = file + (len - 3);
	if (!ft_strncmp(".rt", str, 4))
		return (0);
	return (1);
}

void	read_input(t_input *data, char *file)
{
	if (check_fextension(file))
		error_file("Error\n file extention not .rt");
	get_input(&data->fileinput, file);
	// set_input(data);
}

