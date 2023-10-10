/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validate_object_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 05:40:02 by narin             #+#    #+#             */
/*   Updated: 2023/10/11 02:42:21 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/minirt.h"

/// A real 3d_255
int	check_ambient_light_line(char **splited, t_prog *prog)
{
	size_t	splited_count;
	double	amb_light_ratio;
	t_vec3d co;

	splited_count = count_splited(splited);
	if (splited_count != 3 \
		|| !is_real(splited[1]) \
		|| !is_3d_realnum(splited[2])
	)
		ecerr("- Invalid ambient light line", prog);
	ft_strtod(splited[1], &amb_light_ratio);
	if (amb_light_ratio < 0 || amb_light_ratio > 1)
		ecerr("- Invalid ambient light ratio", prog);
	collect_3d(splited[2], &co);
	if (co.x < 0 || co.y < 0 || co.z < 0 \
		|| co.x > 255 || co.y > 255 || co.z > 255)
		ecerr("- Invalid ambient light color", prog);
	prog->inst_counter.amb_light_count++;
	return (0);
}

// C 3d unit_3d realnum
int	check_camera_line(char **splited, t_prog *prog)
{
	size_t		splited_count;
	double		fov;
	t_vec3d		vec;

	splited_count = count_splited(splited);
	if (splited_count != 4 \
		|| !is_3d_realnum(splited[1]) \
		|| !is_3d_realnum(splited[2]) \
		|| !is_real(splited[3])
	)
		ecerr("- Invalid camera line", prog);
	collect_3d(splited[2], &vec);
	if (fabs(vec.x) > 1 || fabs(vec.y) > 1 || fabs(vec.z) > 1)
		ecerr("- Invalid camera orientation", prog);
	ft_strtod(splited[3], &fov);
	if (fov < 0 || fov > 180)
		ecerr("- Invalid camera fov", prog);
	prog->inst_counter.camera_count++;
	return (0);
}

// R 3d realnum realnum
int check_light_line(char **splited, t_prog *prog)
{
	size_t 	splited_count;
	t_vec3d	vec;
	double	co;

	splited_count = count_splited(splited);
	if (splited_count < 3 \
		|| splited_count > 4 \
		|| !is_3d_realnum(splited[1]) \
		|| !is_real(splited[2])
	)
	{
		printf("splited_count: %zu\n", splited_count);
		error_exit("- Invalid light line", prog);
	}
	if (splited_count == 4)
	{
		if (!is_3d_realnum(splited[3]))
			error_exit("- Invalid light line", prog);
		collect_3d(splited[3], &vec);
		if (is_rgb3d(&vec) == 0)
			ecerr("- Invalid ambient light color", prog);
	}
	ft_strtod(splited[2], &co);
	if (co < 0 || co > 1)
		ecerr("- Invalid light ratio", prog);
	prog->inst_counter.light_count++;
	return (0);
}


int check_plane_line(char **splited, t_prog *prog)
{
	size_t	splited_count;
	t_vec3d	vec;

	splited_count = count_splited(splited);
	if (splited_count != 4 \
		|| !is_3d_realnum(splited[1]) \
		|| !is_3d_realnum(splited[2]) \
		|| !is_3d_realnum(splited[3])
	)
		ecerr("- Invalid plane line", prog);
	collect_3d(splited[2], &vec);
	if (fabs(vec.x) > 1 || fabs(vec.y) > 1 || fabs(vec.z) > 1)
		ecerr("- Invalid plane orientation", prog);
	collect_3d(splited[3], &vec);
	if (is_rgb3d(&vec) == 0)
		ecerr("- Invalid plane color", prog);
	prog->inst_counter.object_count++;
	return (0);
}

int	check_sphere_line(char **splited, t_prog *prog)
{
	size_t	splited_count;
	t_vec3d	vec;
	double	dim;

	splited_count = count_splited(splited);
	if (splited_count != 4 \
		|| !is_3d_realnum(splited[1]) \
		|| !is_real(splited[2]) \
		|| !is_3d_realnum(splited[3])
	)
		ecerr("- Invalid sphere line", prog);
	collect_3d(splited[3], &vec);
	if (is_rgb3d(&vec) == 0)
		ecerr("- Invalid sphere color", prog);
	ft_strtod(splited[2], &dim);
	if (dim < 0)
		ecerr("- Invalid sphere diameter", prog);
	prog->inst_counter.object_count++;
	return (0);
}

int	check_cylinder_line(char **splited, t_prog *prog)
{
	size_t	splited_count;
	t_vec3d	vec;
	double	dim;

	splited_count = count_splited(splited);
	if (splited_count != 6 \
		|| !is_3d_realnum(splited[1]) \
		|| !is_3d_realnum(splited[2]) \
		|| !is_real(splited[3]) \
		|| !is_real(splited[4]) \
		|| !is_3d_realnum(splited[5])
	)
		ecerr("- Invalid cylinder line", prog);
	collect_3d(splited[2], &vec);
	if (fabs(vec.x) > 1 || fabs(vec.y) > 1 || fabs(vec.z) > 1)
		ecerr("- Invalid cylinder orientation", prog);
	collect_3d(splited[5], &vec);
	if (is_rgb3d(&vec) == 0)
		ecerr("- Invalid cylinder color", prog);
	ft_strtod(splited[3], &dim);
	if (dim < 0)
		ecerr("- Invalid cylinder diameter", prog);
	ft_strtod(splited[4], &dim);
	if (dim < 0)
		ecerr("- Invalid cylinder height", prog);
	prog->inst_counter.object_count++;
	return (0);
}