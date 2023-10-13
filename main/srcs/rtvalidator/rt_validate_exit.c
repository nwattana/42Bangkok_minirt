/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validate_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 05:07:46 by narin             #+#    #+#             */
/*   Updated: 2023/10/14 02:11:24 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static	void	print_inst_cout(t_inst_counter *ins)
{
	printf("camera_count = %d\n", ins->camera_count);
	printf("Light count = %d\n", ins->light_count);
	printf("Ambient Count = %d\n", ins->amb_light_count);
	printf("Object count = %d\n", ins->object_count);
	
}

void	check_inst_count(t_prog *prog)
{
	t_inst_counter	*ins;

	ins = &(prog->inst_counter);
	print_inst_cout(ins);
	if (ins->camera_count == 0)
		error_exit("- No camera given", prog);
	if (ins->camera_count > 1)
		error_exit("- Too many cameras given", prog);
	if (ins->light_count > 1)
		error_exit("- Too many lights given", prog);
	if (ins->amb_light_count > 1)
		error_exit("- Too many ambient lights given", prog);
}
