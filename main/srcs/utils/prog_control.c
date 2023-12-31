/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narin <narin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:52:32 by lsomrat           #+#    #+#             */
/*   Updated: 2023/10/10 01:57:45 by narin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	prep_exit(t_prog *prog)
{
	t_list	*lst;

	lst = prog->obj;
	ft_lstiter(lst, clean_object_from_list);
	lst = NULL;
	return (SUCCESS);
}

int	kb_talk(char *mess, int nl)
{
	printf(BLUE"Key"CLOSE);
	printf(": %s", mess);
	if (nl)
	{
		printf("\n");
	}
	return (SUCCESS);
}
