/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:04:29 by lsomrat           #+#    #+#             */
/*   Updated: 2023/10/14 05:07:15 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	is_parallel(t_vec3d *v1, t_vec3d *v2)
{
	double	dot;
	double	len1;
	double	len2;

	dot = vec3d_dot(v1, v2);
	len1 = vec3d_length(v1);
	len2 = vec3d_length(v2);
	if (dot == len1 * len2)
		return (1);
	else
		return (0);
}

void	init_camera(t_camera *camera)
{
	camera->len = cale_camera_len(camera);
	camera->aspect_ratio = WINDOW_WIDTH / WINDOW_HEIGHT;
	camera_look_at(camera);
	camera_up_vector(camera);
	camera_right_vector(camera);
	camera_top_left_vector(camera);
}

void	camera_look_at(t_camera *camera)
{
	t_vec3d	look_at;

	vec3d_plus(&look_at, &camera->position, &camera->normal);
	vec3d_minus(&camera->look_at, &look_at, &camera->position);
	if (vec3d_normalize(&camera->look_at))
	{
		print_vec3d(&camera->look_at, "look_at");
		debug_message("normalize look_at failed: init_camera\n");
	}
}

void	camera_top_left_vector(t_camera *cam)
{
	t_vec3d	aux;
	t_vec3d	aux2;
	t_vec3d	aux3;
	double	aux_cale;

	aux_cale = WINDOW_WIDTH / 2;
	aux_cale = aux_cale / (2.0 * tan(cam->fov * (PI / 180.0) / 2.0));
	ft_memcpy(&aux, &cam->look_at, sizeof(t_vec3d));
	vec3d_normalize(&aux);
	vec3d_scale(&aux, aux_cale, &aux);
	vec3d_scale(&aux2, WINDOW_WIDTH / 2, &cam->u);
	vec3d_scale(&aux3, WINDOW_HEIGHT / 2, &cam->v);
	vec3d_minus(&cam->top_left, &aux, &aux2);
	vec3d_minus(&cam->top_left, &cam->top_left, &aux3);
}

void	camera_up_vector(t_camera *camera)
{
	t_vec3d	world_up;

	world_up = (t_vec3d){0, 1, 0};
	if (is_parallel(&camera->look_at, &world_up))
	{
		world_up = (t_vec3d){0, 0, -1};
		debug_message("camera look_at is parallel to world_up\n");
	}
	vec3d_cross(&camera->u, &camera->look_at, &world_up);
	if (vec3d_normalize(&camera->u))
	{
		debug_message("normalize u failed: init_camera\n");
		exit(1);
	}
}
