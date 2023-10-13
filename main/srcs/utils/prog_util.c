/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:54:48 by lsomrat           #+#    #+#             */
/*   Updated: 2023/10/14 04:36:59 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	prog_constructor(t_prog *prog)
{
	prog->p_state = 1;
	prog->p_error = 0;
	prog->obj = NULL;
	prog->has_camera = 0;
	prog->has_ambient = 0;
	prog->has_light = 0;
	prog->item_count = 0;
	init_inst_counter(&(prog->inst_counter));
	init_validator_util(&(prog->validator_util));
	init_light(&prog->light);
	return (0);
}

void	init_light(t_light *l)
{
	t_color	color;

	color = (t_color){0, 0, 0};
	ft_memcpy(&l->color, &color, sizeof(t_color));
	l->intensity = 0;
}

int	read_rt_file(char *filepath, t_prog *prog)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		error_exit("- File not found", prog);
	while (1)
	{
		line = get_next_line(fd);
		strreplace_space(line);
		if (!line)
			break ;
		check_line(line, prog);
		free(line);
	}
	close(fd);
	return (0);
}

int	read_2bytes(char *line)
{
	if (line == NULL)
		return (0);
	if (ft_strchr("C#ALspc", line[0]))
		return (1);
	return (0);
}
