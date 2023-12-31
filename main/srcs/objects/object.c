/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:59:29 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 01:00:10 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_object_from_list(void *list)
{
	t_object	*object;
	t_list		*lst;

	if (list == NULL)
	{
		printf("NULL list was passed into print_object_fromlist\n");
		return ;
	}
	lst = (t_list *)list;
	object = lst->content;
	object->print(object->object);
}

void	print_object_iter(void *content)
{
	t_object	*object;

	object = (t_object *)content;
	object->print(object->object);
}

void	clean_object_from_list(void *obj)
{
	t_object	*object;

	if (obj == NULL)
	{
		printf("NULL list was passed into clean_object_from_list\n");
		return ;
	}
	object = (t_object *)obj;
	if (object->clean == NULL)
	{
		printf("object->clean type %d is NULL\n", object->type);
		return ;
	}
	object->clean(object->object);
	free(object);
}
