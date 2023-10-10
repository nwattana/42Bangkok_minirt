/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:54:36 by narin             #+#    #+#             */
/*   Updated: 2023/10/10 06:41:01 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	error_exit(char *msg, t_prog *prog)
{
	(void)prog;
	printf(RED"Error\n"CLOSE);
	printf("%s\n", msg);
	exit(1);
}
