/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:01:36 by nwattana          #+#    #+#             */
/*   Updated: 2023/08/24 23:11:30 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

/// @brief t_coordinates is a struct that contains the coordinates {x, y, z}.
typedef struct s_coordinates
{
    double	x;
    double	y;
    double	z;
}	t_coordinates;

/// @brief t_vector is a struct that contains the vector {i, j, k}.
/// @param i is a double that contains the i vector.
/// @param j is a double that contains the j vector.
/// @param k is a double that contains the k vector.
typedef struct s_vector
{
    double	x;
    double	y;
    double	z;
}	t_vector;

/// @brief t_color is a struct that contains the color {red, green, blue}.
/// @param red is an int that contains the red color.
/// @param green is an int that contains the green color.
/// @param blue is an int that contains the blue color.
typedef struct s_color
{
    int	red;
    int	green;
    int	blue;
}	t_color;

/// @brief t_resolution is a struct that contains the resolution {width, height}.
typedef struct s_resolution
{
    int	width;
    int	height;
}	t_resolution;

/// @brief t_ambient is a struct that contains the ambient's ratio and color.
/// @param ratio is a double that contains the ambient's ratio.
typedef struct s_ambient
{
    double	ratio;
    t_color	color;
}	t_ambient;

/// @brief  t_camera is a struct that contains the camera's origin, orientation, and fov.
/// @param  origin is a t_vector that contains the camera's origin.
/// @param  orientation is a t_vector that contains the camera's orientation.
/// @param  fov is an int that contains the camera's fov.
typedef struct s_camera
{
    t_vector	origin;
    t_vector	orientation;
    int		fov;
}	t_camera;

/// @brief t_light is a struct that contains the light's origin, ratio, and color.
/// @param origin is a t_vector that contains the light's origin.
/// @param ratio is a double that contains the light's ratio.
/// @param color is a t_color that contains the light's color.
typedef struct s_light
{
    t_vector	origin;
    double	ratio;
    t_color	color;
}	t_light;

/// @brief t_sphere is a struct that contains the sphere's origin, diameter, and color.
/// @param origin is a t_vector that contains the sphere's origin.
/// @param diameter is a double that contains the sphere's diameter.
typedef struct s_sphere
{
    t_vector	origin;
    double	diameter;
    t_color	color;
}	t_sphere;


/// @brief t_plane is a struct that contains the plane's origin, orientation, and color.
/// @param origin is a t_vector that contains the plane's origin.
/// @param orientation is a t_vector that contains the plane's orientation.
/// @param color is a t_color that contains the plane's color.
typedef struct s_plane
{
    t_vector	origin;
    t_vector	orientation;
    t_color	color;
}	t_plane;

/// @brief t_square is a struct that contains the square's origin, orientation, size, and color.
/// @param origin is a t_vector that contains the square's origin.
/// @param orientation is a t_vector that contains the square's orientation.
/// @param size is a double that contains the square's size.
typedef struct s_square
{
    t_vector	origin;
    t_vector	orientation;
    double	size;
    t_color	color;
}	t_square;

/// @brief t_cylinder is a struct that contains the cylinder's origin, orientation, diameter, height, and color.
/// @param origin is a t_vector that contains the cylinder's origin {x, y, z}.
/// @param orientation is a t_vector that contains the cylinder's orientation {i, j, k}.
/// @param diameter is a double that contains the cylinder's diameter.
/// @param height is a double that contains the cylinder's height.
/// @param color is a t_color that contains the cylinder's color {red, green, blue}.
typedef struct s_cylinder
{
    t_vector	origin;
    t_vector	orientation;
    double	diameter;
    double	height;
    t_color	color;
}	t_cylinder;

/// @brief t_ray is a struct that contains the ray's origin and direction.
typedef struct s_ray
{
    t_vector    origin;
    t_vector    direction;

}       t_ray;

typedef struct s_monitor_coord
{
    double	x;
    double	y;
}	t_monitor_coord;

typedef struct s_metric44
{
    double  c[16];
    int     size;
}           t_metric44;

#endif
