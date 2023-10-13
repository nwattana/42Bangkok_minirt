/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validrealnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:42:36 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/14 04:02:09 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	relv_init(t_realv *rel)
{
	rel->is_minus = 0;
	rel->is_dot = 0;
	rel->prefix = 0;
	rel->dot_count = 0;
	rel->len = 0;
	rel->i = 0;
	rel->pass_dot = 0;
	rel->pre_dot = 0;
	rel->bypass = 1;
}

int	is_escape_zero(char *s, t_realv *r)
{
	if (s[r->i] == '0' && s[r->i + 1] == '0')
		return (1);
	return (0);
}

void	update_iter(t_realv *r)
{
	r->i++;
	if (r->dot_count == 0)
		r->pre_dot++;
	else if (r->dot_count == 1)
		r->pass_dot++;
	else
		r->bypass = 0;
	if (r->dot_count == 1 && r->pre_dot < 1)
		r->bypass = 0;
	if (r->prefix == 1 && r->len == 1)
		r->bypass = 0;
}

int	valid_realnul(t_realv *r, char *str)
{
	(void) str;
	if (r->dot_count != 0)
	{
		if (r->pass_dot == 0 || r->pre_dot == 0)
		{
			debug_message(" NOT FULL NUMBER");
			return (1);
		}
	}
	if (r->prefix >= 1 && r->pre_dot == 0)
	{
		debug_message(" only SINGLE prefix");
		return (1);
	}
	if (r->bypass == 0)
		return (1);
	return (0);
}

/// @brief is a number return 1, not a number return 0
int	is_real(char *str)
{
	t_realv	r;

	relv_init(&r);
	r.len = ft_strlen(str);
	if (str[r.i] == '-')
	{
		r.prefix = 1;
		r.i++;
	}
	if (is_escape_zero(str, &r))
		return (0);
	while (str[r.i] != '\0' && r.bypass)
	{
		if (str[r.i] == '.')
		{
			r.dot_count++;
			r.i++;
		}
		else if (ft_isdigit(str[r.i]) == 0)
			return (0);
		else
			update_iter(&r);
	}
	return (!valid_realnul(&r, str));
}
