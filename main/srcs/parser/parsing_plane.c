/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:46:47 by lsomrat           #+#    #+#             */
/*   Updated: 2023/10/08 00:46:49 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	collect_plane(char **str, t_prog *prog)
{
	t_plane		*plane;
	t_object	*object;

	plane = malloc(sizeof(t_plane));
	if (plane == NULL)
		return (1);
	collect_3d(str[1], &plane->point);
	collect_3d(str[2], &plane->normal);
	color_collect_string(str[3], &plane->color);
	object = create_object_plane(plane);
	if (object == NULL)
		return (1);
	prog->item_count++;
	object->id = prog->item_count;
	ft_lstadd_back(&prog->obj, ft_lstnew(object));
	return (0);
}

t_object	*create_object_plane(t_plane *plane)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (object == NULL)
		return (0);
	object->type = PLANE;
	object->object = plane;
	object->print = print_plane;
	object->clean = clean_plane;
	object->test_intersection = pl_test_intersection;
	return (object);
}
