/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:48:23 by narin             #+#    #+#             */
/*   Updated: 2023/10/10 05:48:18 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	validate_args(int argc, char **argv, t_prog *prog)
{
	size_t	len;

	if (argc < 2)
		error_exit("- No arguments", prog);
	if (argc != 2)
		error_exit("- Too many arguments", prog);
	len = ft_strlen(argv[1]);
	if (len < 4)
		error_exit("- Wrong file extension", prog);
	if (ft_strncmp(argv[1] + len - 3, ".rt", 3) != 0)
		error_exit("- Wrong file extension", prog);
	return (0);
}

int	pre_read_config(char **argv, t_prog *prog)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit("- File not found", prog);
	line = get_next_line(fd);
	while (line)
	{
		ret = check_line_no_implement(line, prog);
		free(line);
		if (ret != 0)
		{
			error_exit("- Invalid file", prog);
		}
		line = get_next_line(fd);
	}
	debug_inst_counter(&(prog->inst_counter));
	check_inst_count(prog);
	// NOTE validate config end here
	return (0);
}

int check_line_no_implement(char *line, t_prog *prog)
{
	char 	*trimed;
	int		error;
	char	**split_out;

	error = 0;
	if (line == NULL)
		return (0);
	if (ft_strlen(line) == 0)
		return (1);
	trimed = ft_strtrim(line, " \t\n");
	if (trimed == NULL)
		return (1);
	split_out = ft_split(trimed, ' ');
	if (split_out == NULL)
		return (1);
	error = feed_check_config(split_out, prog);
	free(trimed);
	ft_free_split(split_out);
	return (error);
}

// splited free ข้างนอก
int feed_check_config(char **splited, t_prog *prog)
{
	int error;

	(void)prog;
	error = 0;
	if (!splited)
		return (1);
	if (valid_line_prefix(splited[0], prog))
	{
		printf("%s not in prefix set\n", splited[0]);
		return (1);
	}
	if (valid_line_instruction(splited, prog))
	{
		return (1);
	}
	return (error);
}

// are component in C A L # pl cy sp and empty line
int valid_line_prefix(char *prefix, t_prog *prog)
{
	(void)prog;
	if (prefix == NULL)
		return (0);
	if (ft_strlen(prefix) == 0)
		return (0);
	printf("%s\n", prefix);
	if (ft_strcmp(prefix, "C") == 0)
		return (0);
	else if (ft_strcmp(prefix, "A") == 0)
		return (0);
	else if (ft_strcmp(prefix, "L") == 0)
		return (0);
	else if (ft_strcmp(prefix, "pl") == 0)
		return (0);
	else if (ft_strcmp(prefix, "cy") == 0)
		return (0);
	else if (ft_strcmp(prefix, "sp") == 0)
		return (0);
	return (1);
}

int	valid_line_instruction(char **splited, t_prog *prog)
{
	int error;

	error = 0;
	if (ft_strcmp(splited[0], "A") == 0)
		error = check_ambient_light_line(splited, prog);
	else if (ft_strcmp(splited[0], "C") == 0)
		error = check_camera_line(splited, prog);
	else
		error = 1;
	// else if (ft_strcmp(splited[0], "L") == 0)
	// 	error = check_light_line(splited, prog);
	// else if (ft_strcmp(splited[0], "pl") == 0)
	// 	error = check_plane_line(splited, prog);
	// else if (ft_strcmp(splited[0], "cy") == 0)
	// 	error = check_cylinder_line(splited, prog);
	// else if (ft_strcmp(splited[0], "sp") == 0)
	// 	error = check_sphere_line(splited, prog);
	return (error);
}

int	is_skip_line(char *line)
{
	if (line == NULL)
		return (1);
	if (ft_strlen(line) == 0)
		return (1);
	if (ft_strncmp(line, "#", 1) == 0)
		return (1);
	return (0);
}

void init_inst_counter(t_inst_counter *ins)
{
	ins->camera_count = 0;
	ins->light_count = 0;
	ins->object_count = 0;
	ins->amb_light_count = 0;
}