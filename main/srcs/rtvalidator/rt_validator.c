/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:48:23 by narin             #+#    #+#             */
/*   Updated: 2023/10/11 02:54:10 by narin            ###   ########.fr       */
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

// loop line by line here
int	pre_read_config(char **argv, t_prog *prog)
{
	t_validator_util	*util;

	util = &(prog->validator_util);
	util->opened_fd = open(argv[1], O_RDONLY);
	if (util->opened_fd < 0)
		error_exit("- File not found", prog);
	util->is_open_fd = 1;
	util->gnl_line = get_next_line(util->opened_fd);
	while (util->gnl_line)
	{
		check_line_no_implement(util->gnl_line, prog);
		free_set_null(&util->gnl_line);
		is_validate_error(prog);
		util->gnl_line = get_next_line(util->opened_fd);
	}
	check_inst_count(prog);
	close(util->opened_fd);
	util->is_open_fd = 0;
	return (0);
}

int	check_line_no_implement(char *line, t_prog *prog)
{
	int					error;
	t_validator_util	*util;

	error = 0;
	util = &(prog->validator_util);
	if (line == NULL)
		return (0);
	if (ft_strlen(line) == 0 || is_skip_line(line))
		return (0);
	strreplace_space(line);
	util->trimed = ft_strtrim(line, " \t\n");
	if (util->trimed == NULL)
		ecerr("- ft_strtrim return NULL", prog);
	util->splited = ft_split(util->trimed, ' ');
	if (util->splited == NULL)
		ecerr("- ft_split return NULL", prog);
	error = feed_check_config(util->splited, prog);
	free(util->trimed);
	ft_free_split(util->splited);
	return (error);
}

int	is_skip_line(char *line)
{
	if (line == NULL)
		return (1);
	if (ft_strlen(line) == 0)
		return (1);
	if (ft_strlen(line) == 1 && line[0] == '\n')
		return (1);
	if (ft_strncmp(line, "#", 1) == 0)
		return (1);
	return (0);
}

// splited free ข้างนอก
int	feed_check_config(char **splited, t_prog *prog)
{
	int	error;

	(void)prog;
	error = 0;
	if (!splited)
		return (0);
	if (valid_line_prefix(splited[0], prog))
		ecerr("- Invalid prefix", prog);
	if (valid_line_instruction(splited, prog))
		ecerr("- Invalid instruction", prog);
	return (error);
}
