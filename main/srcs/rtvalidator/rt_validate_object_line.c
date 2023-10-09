/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validate_object_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 05:40:02 by narin             #+#    #+#             */
/*   Updated: 2023/10/10 05:57:44 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/minirt.h"

int	check_ambient_light_line(char **splited, t_prog *prog)
{
	size_t	splited_count;
	double	amb_light_ratio;

	splited_count = count_splited(splited);
	if (splited_count != 3 \
		|| !is_real(splited[1]) \
		|| !is_3d_realnum(splited[2])
	)
		error_exit("- Invalid ambient light line", prog);
	ft_strtod(splited[1], &amb_light_ratio);
	if (amb_light_ratio < 0 || amb_light_ratio > 1)
		error_exit("- Invalid ambient light ratio", prog);
	return (0);
}

int	check_camera_line(char **splited, t_prog *prog)
{
	size_t		splited_count;
	double		fov;
	t_vec3d		vec;

	splited_count = count_splited(splited);
	if (splited_count != 4\
		|| !is_3d_realnum(splited[1]) \
		|| !is_3d_realnum(splited[2]) \
		|| !is_real(splited[3])
	)
		error_exit("- Invalid camera line", prog);
	collect_3d(splited[2], &vec);
	if (vec.x < -1 || vec.x > 1 || vec.y < -1 || vec.y > 1 || vec.z < -1 || vec.z > 1)
		error_exit("- Invalid camera orientation", prog);
	if (vec3d_length(&vec) != 1)
		error_exit("- Invalid camera orientation", prog);
	ft_strtod(splited[3], &fov);
	if (fov < 0 || fov > 180)
		error_exit("- Invalid camera fov must be in range 1-179 degree", prog);
	prog->inst_counter.camera_count++;
	return (0);
}

int check_light_line(char **splited, t_prog *prog)
{
	size_t 	splited_count;
	// double	temp;
	// t_vec3d	vec;

	splited_count = count_splited(splited);
	if (splited_count != 4 \
		|| !is_3d_realnum(splited[1]) \
		|| !is_real(splited[2]) \
		|| !is_3d_realnum(splited[3])
	)
		error_exit("- Invalid light line", prog);

	prog->inst_counter.light_count++;
	return (0);
}
