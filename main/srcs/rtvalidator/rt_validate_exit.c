/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validate_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 05:07:46 by narin             #+#    #+#             */
/*   Updated: 2023/10/11 02:41:53 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	check_inst_count(t_prog *prog)
{
	t_inst_counter	*ins;

	ins = &(prog->inst_counter);
	printf("camera_count = %d\n", ins->camera_count);
	if (ins->camera_count == 0)
		error_exit("- No camera given", prog);
	if (ins->camera_count > 1)
		error_exit("- Too many cameras given", prog);
	if (ins->light_count > 1)
		error_exit("- Too many lights given", prog);
	if (ins->amb_light_count > 1)
		error_exit("- Too many ambient lights given", prog);
}
