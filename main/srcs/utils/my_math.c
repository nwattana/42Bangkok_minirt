/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:47:58 by lsomrat           #+#    #+#             */
/*   Updated: 2023/10/07 23:48:01 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	solve_quadratic(double a, double b, double c)
{
	double	test;
	double	t1;
	double	t2;
	double	testsqr;

	test = b * b - 4.0 * a * c;
	if (test < 0.0)
		return (-1);
	testsqr = sqrt(test);
	if (test > 0.0)
	{
		t1 = (-b + testsqr) / (2.0 * a);
		t2 = (-b - testsqr) / (2.0 * a);
		if (t1 < 0.0 || t2 < 0.0)
			return (-1);
		if (t1 < t2)
			return (t1);
		else
			return (t2);
	}
	return (-1);
}
