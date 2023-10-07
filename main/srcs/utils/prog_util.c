/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:54:48 by lsomrat           #+#    #+#             */
/*   Updated: 2023/10/07 23:54:49 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	error_exit(char *msg, t_prog *prog)
{
	printf("%s", msg);
	exit(prog->p_state);
}

int	validate_args(int argc, char **argv, t_prog *prog)
{
	int		i;
	size_t	len;

	i = 0;
	if (argc < 2)
		error_exit("Error\nNo arguments\n", prog);
	if (argc != 2)
		error_exit("Error\nToo many arguments\n", prog);
	len = ft_strlen(argv[1]);
	if (len < 4)
		error_exit("Error\nWrong file extension\n", prog);
	if (ft_strncmp(argv[1] + len - 3, ".rt", 3) != 0)
		error_exit("Error\nWrong file extension\n", prog);
	return (0);
}

int	prog_constructor(t_prog *prog)
{
	prog->p_state = 1;
	prog->p_error = 0;
	prog->obj = NULL;
	prog->has_camera = 0;
	prog->has_ambient = 0;
	prog->has_light = 0;
	prog->item_count = 0;
	return (0);
}

int	read_rt_file(char *filepath, t_prog *prog)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		error_exit("Error\n file not found", prog);
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
