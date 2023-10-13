/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_util_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:00:25 by lsomrat           #+#    #+#             */
/*   Updated: 2023/10/14 02:06:20 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	check_line_type(char **spl, t_prog *prog)
{
	if (ft_strncmp(spl[0], "C", ft_strlen(spl[0])) == 0)
		collect_camera(spl, prog);
	if (ft_strncmp(spl[0], "A", ft_strlen(spl[0])) == 0)
		collect_ambient(spl, prog);
	if (ft_strncmp(spl[0], "L", ft_strlen(spl[0])) == 0)
		collect_light(spl, prog);
	if (ft_strncmp(spl[0], "sp", ft_strlen(spl[0])) == 0)
		collect_sphere(spl, prog);
	if (ft_strncmp(spl[0], "pl", ft_strlen(spl[0])) == 0)
		collect_plane(spl, prog);
	if (ft_strncmp(spl[0], "cy", ft_strlen(spl[0])) == 0)
		collect_cylinder(spl, prog);
	return (0);
}

int	check_line(char *lint, t_prog *prog)
{
	char	**split_out;
	char	*line;
	int		skiped;

	line = ft_strtrim(lint, " \t\n");
	skiped = is_skip_line(line);
	if (!read_2bytes(line))
		prog->p_error = 1;
	if (!skiped)
	{
		split_out = ft_split(line, ' ');
		check_line_type(split_out, prog);
		ft_free_split(split_out);
	}
	free(line);
	return (0);
}

int	count_char(char *str, int c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
		{
			counter++;
		}
		i++;
	}
	return (counter);
}

void	debug_message(char *msg)
{
	ft_putstr_fd(RED"WARNING:"CLOSE, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}
