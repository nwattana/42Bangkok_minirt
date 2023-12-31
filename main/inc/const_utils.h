/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:50:58 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 01:50:59 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_UTILS_H
# define CONST_UTILS_H

# define H_LINE "----------------------------------------\n"
# define H_LINE2 "========================================\n"
# define H_LINE3 "########################################\n"
# define H_LINE4 "++++++++++++++++++++++++++++++++++++++++\n"
# define H_LINE5 "****************************************\n"
# define SUCCESS 0
# define ERROR 1

//string color
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define CLOSE "\033[0m"

# define FWD 1
# define BWD -1
# define EPSILON 1e-21f

# define CAMERA 1
# define CAMERA_ID -1
# define AMBIENT 2
# define LIGHT 3

// TYPE more than 10 is reserved for objects
# define SPHERE 20
# define PLANE 21
# define CYLINDER 22

# define NONE_ID 0

#endif