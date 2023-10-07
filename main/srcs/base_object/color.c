/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:23:24 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/07 23:27:15 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	color_collect_string(char *color_string, t_color *color)
{
	char	**spl_c;

	spl_c = ft_split(color_string, ',');
	if (spl_c == NULL)
		return (1);
	color->r = ft_atoi(spl_c[0]);
	color->g = ft_atoi(spl_c[1]);
	color->b = ft_atoi(spl_c[2]);
	ft_free_split(spl_c);
	return (0);
}

int	color_init(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
	return (0);
}

int	color_struct2int(t_color *color)
{
	return (color_rgb2int(color->r, color->g, color->b));
}

int	color_scale(t_color *res, double scale, t_color *a)
{
	res->r = (scale * (double)a->r);
	res->g = (scale * (double)a->g);
	res->b = (scale * (double)a->b);
	return (0);
}
