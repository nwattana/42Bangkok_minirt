/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:57:02 by nwattana          #+#    #+#             */
/*   Updated: 2023/10/08 02:11:50 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# include "../zlib/libft.h"
# include "../zlib/get_next_line.h"
# include "../mlx/mlx.h"
# include "const_utils.h"
# include "vector.h"
# include "mlx_config.h"
# include "prog_state.h"

# define PROGRAM_NAME "miniRT"
# define WINDOW_WIDTH 640.0f
# define WINDOW_HEIGHT 360.0f
# define PI 3.14159265358979323846f
# define DEBUG 1
# define WORLD_SCALE 1.0f

typedef struct s_interparam	t_interparam ;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_object
{
	int		type;
	void	*object;
	int		id;
	void	(*print)(void *object);
	void	(*clean)(void *object);
	int		(*test_intersection)(void *object, t_interparam *param);
}			t_object;

typedef struct s_camera
{
	t_vec3d	position;
	t_vec3d		normal;
	double		fov;
	double		fov_rad;
	double		len;
	double		aspect_ratio;
	t_vec3d		world_up;
	t_vec3d		look_at;
	t_vec3d		u;
	t_vec3d		v;
	t_vec3d		top_left;
}	t_camera;

typedef struct s_light
{
	t_vec3d	position;
	t_color		color;
	double		intensity;
}				t_light;

typedef struct s_ray
{
	t_vec3d	origin;
	t_vec3d		direction;
}			t_ray;

typedef struct s_plane
{
	t_vec3d		point;
	t_vec3d		normal;
	t_color		color;
}				t_plane;

typedef struct s_interparam
{
	t_ray		*ray;
	int			start_ray_obj_id;
	int			hit;
	double		f_dist;
	int			f_ishit;
	t_object	*f_obj;
	t_vec3d		f_normal;
	t_vec3d		f_point;
	t_color		f_color;
	double		inters_dist;
	int			inters_obj_id;
	t_vec3d	inters_point;
	t_vec3d		inters_normal;
	t_color		inters_color;
	int			d_inters_obj_type;
	t_color		final_color;
}	t_interparam;

typedef struct s_sphere
{
	t_vec3d	center;
	double		radius;
	t_color		color;
}				t_sphere;

typedef struct s_prog
{
	int				p_state;
	int				p_error;
	t_list			*obj;
	t_mlx_confix	mlx_config;
	int				has_camera;
	int				has_ambient;
	int				has_light;
	t_camera		camera;
	t_light			light;
	t_color			ambient_color;
	double			ambient_intensity;
	void			*selected_obj;
	int				sel_type;
	int				sel_axis;
	int				x;
	int				y;
	int				item_count;
	t_list			*cur_obj;
}	t_prog;

typedef struct s_slight
{
	t_color		light_color;
	t_color		ambient_color;
}			t_slight;

typedef struct s_Cylinder
{
	t_vec3d	point;
	double		radi;
	double		len;
	t_vec3d		normal;
	t_color		color;
}				t_cylinder;

typedef struct s_obslight
{
	t_ray		ray;
	t_vec3d		light_dir;
	double		angle;
	double		max_dist;
	double		angle_scale;
	int			inters_obj;
	double		scale_angle;
	int			stuck;
	t_slight	light;
}				t_obslight;

typedef struct s_minter
{
	t_vec3d	sp_inters;
	t_vec3d		sinter_normal;
	t_color		sp_ints2inside;
	t_color		sp_dist;
}				t_minter;

int			validate_args(int argc, \
	char **argv, t_prog *prog);
int			prog_constructor(t_prog *prog);
void		error_exit(char *msg, t_prog *prog);
int			read_rt_file(char *filepath, t_prog *prog);
int			check_line(char *line, t_prog *prog);
int			check_line_type(char **splited_lint, t_prog *prog);
int			read_2bytes(char *line);
int			count_char(char *str, int c);
int			collect_camera(char **splited_line, t_prog *prog);
int			collect_ambient(char **split_line, t_prog *prog);
int			collect_light(char **splited_line, t_prog *prog);
int			collect_sphere(char **splited_line, t_prog *prog);
int			collect_plane(char **str, t_prog *prog);
int			sp_intersection_normal(t_vec3d *normal, \
	t_vec3d *inters, t_vec3d *center);
int			sp_intersection_point(t_vec3d *inters, t_ray *ray, double dist);
double		cale_camera_len(t_camera *camera);
void		clean_plane(void *pl);
void		print_plane(void *pl);
int			pl_test_intersection(void *obj, t_interparam *param);
int			pl_sub_intersect(t_plane *plane, t_interparam *param);
void		clean_cylinder(void *object);
void		print_cylinder(void *object);
t_object	*create_object_cylinder(t_cylinder *cylinder);
int			collect_cylinder(char **str, t_prog *prog);
int			cy_test_intersection(void *object, t_interparam *p);
void		print_light(void *light);
void		clean_light(void *light);
void		print_sphere(void *sphere);
void		clean_sphere(void *sphere);
int			sp_test_intersection(void *object, t_interparam *p);
int			color_init(t_color *color, int r, int g, int b);
int			color_plus(t_color *res, t_color *a, t_color *b);
int			color_struct2int(t_color *color);
int			color_rgb2int(int r, int g, int b);
int			color_collect_string(char *color_string, t_color *color);
int			color_scale(t_color *res, double scale, t_color *a);
int			print_color(t_color *color);
int			color_plus(t_color *res, t_color *a, t_color *b);
int			color_copy(t_color *dst, t_color *src);
t_color		int2color(int color);
void		color_set_defval(t_color *color);
int			color_dot(t_color *res, t_color *c1, t_color *c2);
void		init_camera(t_camera *cam);
void		print_object_from_list(void *lst);
void		clean_object_from_list(void *obj);
void		print_object_iter(void *content);
void		*get_object_from_list(t_list *lst, int type);
int			none_test_intersection(void *object, t_interparam *param);
t_object	*create_object_sphere(t_sphere *sp);
t_object	*create_object_plane(t_plane *plane);
void		generate_ray(t_ray *ray, t_prog *prog, int x, int y);
int			init_intersection_param(t_prog *prog, \
	t_ray *ray, t_interparam *param);
int			trace_ray_to_obj(t_prog *prog, t_interparam *param);
double		solve_quadratic(double a, double b, double c);
void		prog_init_mlx(t_prog *prog);
int			render_image(t_prog *prog);
void		prog_mlx_loop(t_prog *prog);
void		debug_message(char *msg);
int			reset_inters_focus(t_interparam *param);
int			init_intersection_param(t_prog *prog, \
	t_ray *ray, t_interparam *param);
int			gather_inters_info(t_interparam *param, \
	t_object *focus_obj);
void		init_inters_light_param(t_prog *prog, t_interparam *param, \
	t_obslight *light_param);
int			cale_angle_scale(t_obslight *l_param, t_interparam *p);
int			almost_equal(double a, double b);
void		print_ray(t_ray *ray, char *mess);
int			render_image(t_prog *prog);
void		generate_ray(t_ray *ray, t_prog *prog, int x, int y);
int			ray_color(t_ray *ray, t_prog *prog);
int			trace_inters_to_light(t_prog *prog, \
	t_interparam *param, t_obslight *light_param);
void		trace_light(t_prog *prog, t_interparam *param);
void		print_obj_type(int type);
int			cy_test_intersection(void *object, t_interparam *p);
double		cy_cale_dist(t_ray *ray, t_cylinder *cy);
int			cy_intersection_normal(t_vec3d *normal, \
	t_vec3d *inters, t_vec3d *center);
int			cy_intersection_point(t_vec3d *inters, t_ray *ray, double dist);
int			cy_create_plane(t_plane *pl, t_cylinder *cy);
void		create_mox_inters(t_ray *ray, \
	t_interparam *mox, t_interparam *p);
void		print_inters_param(t_interparam *p);
int			set_inters_from_mox(t_interparam *p, t_interparam *mox);
int			cy_rear(t_cylinder *cy, t_interparam *p);
int			cy_cap(t_cylinder *cy, t_interparam *p);
int			color_collect_string(char *color_string, t_color *color);
int			color_init(t_color *color, int r, int g, int b);
int			color_plus(t_color *res, t_color *a, t_color *b);
int			color_struct2int(t_color *color);
int			color_rgb2int(int r, int g, int b);
int			color_scale(t_color *res, double scale, t_color *a);
void		camera_look_at(t_camera *camera);
void		camera_right_vector(t_camera *camera);
void		camera_up_vector(t_camera *camera);
void		camera_top_left_vector(t_camera *camera);
double		pl_cale_dist(t_ray *ray, t_plane *pl, \
	int *hit, t_interparam *param);
double		sp_cale_dist(t_ray *ray, t_sphere *sp);
int			sp_intersection_point(t_vec3d *inters, \
	t_ray *ray, double dist);
int			sp_intersection_normal(t_vec3d *normal, \
	t_vec3d *inters, t_vec3d *center);
int			kb_talk(char *mess, int nl);
int			re_render(t_prog *prog);
int			select_camera(t_prog *prog);
int			camera_translate_add(t_prog *prog);
int			camera_translate_minus(t_prog *prog);
int			plus_axis(t_prog *prog);
int			minus_axis(t_prog *prog);
int			select_active_axis(t_prog *prog, int kc);
int			rotate_axis(t_prog *prog, double deg);
int			roty_normal(t_vec3d *normal, double deg);
int			rotx_normal(t_vec3d *normal, double deg);
int			rotz_normal(t_vec3d *normal, double deg);
int			rotate_cam(t_prog *prog, double deg);
int			select_obj(t_prog *prog);
int			sp_plus_trans(t_prog *prog);
int			sp_minus_trans(t_prog *prog);
int			cy_minus_trans(t_prog *prog);
int			cy_plus_trans(t_prog *prog);
int			rotate_plane(t_prog *prog, double deg);
int			rotate_cylinder(t_prog *prog, double deg);
int			pl_minus_trans(t_prog *prog);
int			pl_plus_trans(t_prog *prog);
int			perp_exit(int x, t_prog *prog);
#endif
