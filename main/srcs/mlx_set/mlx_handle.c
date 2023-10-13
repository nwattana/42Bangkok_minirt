/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:19:39 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/14 05:04:34 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	keyhandler(int kc, t_prog *prog)
{
	if (kc >= 6 && kc <= 8)
		select_active_axis(prog, kc);
	if (kc == 14)
		rotate_axis(prog, -10);
	if (kc == KEY_Q)
		rotate_axis(prog, 10);
	if (kc == KEY_1)
		select_camera(prog);
	if (kc == KEY_MINUS)
		minus_axis(prog);
	if (kc == KEY_PLUS)
		plus_axis(prog);
	if (kc == KEY_TAB)
		select_obj(prog);
	if (kc == KEY_ESC)
		perp_exit(0, prog);
	return (0);
}

int	select_camera(t_prog *prog)
{
	prog->selected_obj = &prog->camera;
	prog->sel_type = CAMERA;
	kb_talk("CAMERA SLECTED", 1);
	return (SUCCESS);
}

int	select_obj(t_prog *prog)
{
	t_object	*ob;

	if (prog->cur_obj == NULL || prog->cur_obj->next == NULL)
		prog->cur_obj = prog->obj;
	else if (prog->sel_type != CAMERA)
		prog->cur_obj = prog->cur_obj->next;
	if (prog->cur_obj == NULL)
	{
		printf("NO OBJECTS IN SCENE\n");
		return (SUCCESS);
	}
	ob = (t_object *)prog->cur_obj->content;
	prog->sel_type = ob->type;
	ft_putstr_fd("[ ", 1);
	print_obj_type(prog->sel_type);
	ft_putstr_fd(" ] SELECT\n", 1);
	return (SUCCESS);
}

int	rotate_axis(t_prog *prog, double deg)
{
	ft_putstr_fd("Rotate ", 1);
	print_obj_type(prog->sel_type);
	ft_putstr_fd("\n", 1);
	if (prog->sel_type == CAMERA)
		rotate_cam(prog, deg);
	if (prog->sel_type == CYLINDER)
		rotate_cylinder(prog, deg);
	if (prog->sel_type == PLANE)
		rotate_plane(prog, deg);
	re_render(prog);
	return (SUCCESS);
}
