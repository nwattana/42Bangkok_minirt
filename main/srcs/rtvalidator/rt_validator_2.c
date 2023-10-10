/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validator_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 02:53:34 by narin             #+#    #+#             */
/*   Updated: 2023/10/11 02:54:17 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// are component in C A L # pl cy sp and empty line
int	valid_line_prefix(char *prefix, t_prog *prog)
{
	(void)prog;
	if (prefix == NULL)
		return (0);
	if (ft_strlen(prefix) == 0)
		return (0);
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
	int	error;

	error = 0;
	if (ft_strcmp(splited[0], "A") == 0)
		error = check_ambient_light_line(splited, prog);
	else if (ft_strcmp(splited[0], "C") == 0)
		error = check_camera_line(splited, prog);
	else if (ft_strcmp(splited[0], "L") == 0)
		error = check_light_line(splited, prog);
	else if (ft_strcmp(splited[0], "pl") == 0)
		error = check_plane_line(splited, prog);
	else if (ft_strcmp(splited[0], "cy") == 0)
		error = check_cylinder_line(splited, prog);
	else if (ft_strcmp(splited[0], "sp") == 0)
		error = check_sphere_line(splited, prog);
	else
	{
		ecerr("- Instruction not implement", prog);
	}
	return (error);
}
