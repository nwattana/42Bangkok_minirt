/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 06:35:48 by narin             #+#    #+#             */
/*   Updated: 2023/10/11 00:34:22 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/minirt.h"

void	init_validator_util(t_validator_util *util)
{
	util->gnl_line = NULL;
	util->splited = NULL;
	util->trimed = NULL;
	util->err_message = NULL;
	util->is_error = 0;
}

/// @brief use until finish validate process
void	is_validate_error(t_prog *prog)
{	
	t_validator_util *util;

	util = &(prog->validator_util);
	if (util->is_error)
	{
		ft_putstr_fd(RED"Error\n"CLOSE, 2);
		ft_putstr_fd(util->err_message, 2);
		free_set_null(&(util->err_message));
		free(util->gnl_line);
		ft_free_split(util->splited);
		free(util->trimed);
		if (util->is_open_fd)
			clean_gnl_buffer(util->opened_fd);
		exit(1);
	}
}

/// @brief exit cause error
void	ecerr(char *message, t_prog *prog)
{
	t_validator_util *util;

	util = &(prog->validator_util);
	util->is_error = 1;
	util->err_message = ft_strjoin(message, "\n");
	is_validate_error(prog);
}

void	clean_gnl_buffer(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	clean_validator_util(t_prog *prog)
{
	t_validator_util *util;

	util = &(prog->validator_util);
	free_set_null(&(util->err_message));
	free_set_null(&(util->gnl_line));
	ft_free_split(util->splited);
	free_set_null(&(util->trimed));
	if (util->is_open_fd)
	{
		clean_gnl_buffer(util->opened_fd);
	}
}