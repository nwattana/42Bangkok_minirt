/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:54:48 by lsomrat           #+#    #+#             */
/*   Updated: 2023/10/10 06:36:17 by narin            ###   ########.fr       */
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
	return (0);
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
