/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:54:36 by narin             #+#    #+#             */
/*   Updated: 2023/10/14 02:27:45 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	error_exit(char *msg, t_prog *prog)
{
	(void)prog;
	ft_putstr_fd(RED"Error\n"CLOSE, 2);
	printf("%s\n", msg);
	exit(1);
}
