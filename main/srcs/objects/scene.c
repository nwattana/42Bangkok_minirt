#include "../../inc/minirt.h"
typedef struct s_renderer
{
	t_ray 		ray;
	t_color		color_obj;
	t_point3d	intersection_point;
	t_color		local_color;
	t_vec3d		local_normal;

	double		xfact;
	double		yfact;
	double		norm_x;
	double		norm_y;

	int			color;
	double 		min_dist;
	double 		max_dist;
	t_vec3d 	origin_to_intersection;
	t_object	*cam;
	int			has_intersection;
	double 		dist;

}			t_renderer;

int		which_color_should_be(t_prog *prog, int x, int y, t_renderer *renderer);
int	cal_light(t_prog *prog, t_renderer *renderer, t_interparam *param);
int	init_intersection_param(t_interparam *param, t_prog *prog);
int  init_renderer(t_renderer *ren, t_prog *prog)
{
	if (!ren)
		return (ERROR);
	ren->color = 0;
	ren->xfact = 1.0 / ((double)WINDOW_WIDTH / 2.0);
	ren->yfact = 1.0 / ((double)WINDOW_HEIGHT / 2.0);
	ren->min_dist = INFINITY;
	ren->max_dist = -INFINITY;
	ren->cam = get_object_from_list(prog->obj, CAMERA);
	if (!ren->cam)
	{
		debug_message("No camera found");
		exit(1);
	}
}

/// @return 0 if on sucess, 1 if error
int render_image(t_prog *prog)
{
	t_renderer renderer;
	t_list *lst;
	int x;
	int y;

	init_renderer(&renderer, prog);
	prog->p_state = RENDERING;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			renderer.color = which_color_should_be(prog, x, y, &renderer);
			mlx_my_putpixel(&(prog->mlx_config.img), x, y, renderer.color);
			y++;
		}
		x++;
	}
    return (SUCCESS);
}

// which_color_should_be
int which_color_should_be(t_prog *prog, int x, int y, t_renderer *renderer)
{
	t_object 		*l_obj;

	l_obj = get_object_from_list(prog->obj, LIGHT);
	t_interparam 	param;

	renderer->norm_x = ((double)x* renderer->xfact) - 1.0;
	renderer->norm_y = ((double)y * renderer->yfact) - 1.0;
	init_intersection_param(&param, prog);
	// หมุนกล้องไม่ได้
	generate_ray(&param.ray, renderer->cam->object, renderer->norm_x, renderer->norm_y);

	renderer->has_intersection = loop_test_object(prog, &param);
	if (renderer->has_intersection)
	{
		cal_light(prog, renderer, &param);
	}
	else
	{
		renderer->color = s_get_rgb(&prog->defval.color_purple);
	}
}

// return 1 if intersection, 0 if not all param passing with `param`
int loop_test_object(t_prog *prog, t_interparam *param)
{
	t_list		*lst;
	t_object	*obj;
	int			ret;
	int			test;

	ret = 0;
	lst = prog->obj;
	while (lst)
	{
		obj = (t_object *)lst->content;
		if (obj->type >= 20)
		{
			// test distance for each object in intersection
			test = obj->test_intersection(obj, param);
			if (test != 0)
				ret = test;
		}
		lst = lst->next;
	}
	return (ret);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

// INIT intersection paramert for each loop on x,y screen coordinate
int	init_intersection_param(t_interparam *param, t_prog *prog)
{
	t_defval *defalt;

	if (!param)
	{
		debug_message("Intersection parameter is null");
		exit(ERROR);
	}
	defalt = &prog->defval;
	param->min_dist = INFINITY;
	param->intersection_obj = NULL;
	param->intensity = 0;
	param->color = defalt->color_white.value;
	param->ray.is_init = 0;

	return (SUCCESS);
}

int	cal_light(t_prog *prog, t_renderer *renderer, t_interparam *param)
{
	t_object *l_obj;
	int			valid_light = 0;

	l_obj = get_object_from_list(prog->obj, LIGHT);

	valid_light = point_light(l_obj->object, param);
	if (valid_light)
	{
		color_scale(&param->local_color, param->intensity, &param->local_color);
		renderer->color = s_get_rgb(&param->local_color);
	}
}
