/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validate_object_line_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 02:50:59 by narin             #+#    #+#             */
/*   Updated: 2023/10/11 02:59:28 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

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
	if (splited_count != 6 || !is_3d_realnum(splited[1]) \
		|| !is_3d_realnum(splited[2]) || !is_real(splited[3]) \
		|| !is_real(splited[4]) || !is_3d_realnum(splited[5])
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
