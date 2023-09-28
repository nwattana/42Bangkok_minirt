#include "../../inc/minirt.h"

typedef struct s_renderer
{
	// loop variable
	int			win_x;
	int			win_y;

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




int  init_renderer(t_renderer *ren, t_prog *prog)
{
	if (!ren)
		return (ERROR);
	ren->win_x = 0;
	ren->win_y = 0;
	ren->color = 0;
	ren->xfact = 1.0 / ((double)WINDOW_WIDTH / 2.0);
	ren->yfact = 1.0 / ((double)WINDOW_HEIGHT / 2.0);
	ren->min_dist = INFINITY;
	ren->max_dist = -INFINITY;
	ren->cam = get_object_from_list(prog->obj, CAMERA);
}

/// @return 0 if on sucess, 1 if error
int render_image(t_prog *prog)
{
	t_renderer renderer;
	t_interparam param;
	t_object *l_obj;
	t_list *lst;


	l_obj = get_object_from_list(prog->obj, LIGHT);
	l_obj->print(l_obj->object);
	init_renderer(&renderer, prog);
	prog->p_state = RENDERING;
	renderer.cam->print(renderer.cam->object);

	renderer.win_x = 0;
	while (renderer.win_x < WINDOW_WIDTH)
	{
		// normalize x
		renderer.norm_x = ((double)renderer.win_x * renderer.xfact) - 1.0f;
		renderer.win_y = 0;
		while (renderer.win_y < WINDOW_HEIGHT)
		{
			renderer.norm_y = ((double)renderer.win_y * renderer.yfact) - 1.0f;
			generate_ray(&param.ray, renderer.cam->object, renderer.norm_x, renderer.norm_y);

			// renderer.has_intersection = sp_test_intersection(&renderer.ray, &renderer.intersection_point, &renderer.local_normal, &renderer.local_color);
			renderer.has_intersection = loop_test_object(prog, &param);

			if (renderer.has_intersection)
			{
				vec3d_minus(&renderer.origin_to_intersection, &param.intersection_point, &param.ray.origin);
				renderer.dist = vec3d_length(&renderer.origin_to_intersection);
				// เปลี่ยน method ในการคำนวณสี
				double intensity = 0;
				t_color l_color;
				int		valid_light = 0;

				valid_light = point_light(l_obj->object, prog->obj, &param, &l_color, &intensity);
				if (valid_light)
				{
					t_color color_result;

					// add ambient?
					assign_color(&color_result, 255.0 * intensity, 0,0);
					color_add(&color_result, &color_result, &prog->ambient_color);
					renderer.color = s_get_rgb(&color_result);
				}
				if (renderer.dist < renderer.min_dist)
					renderer.min_dist = renderer.dist;
				if (renderer.dist > renderer.max_dist)
					renderer.max_dist = renderer.dist;
			}
			else
			{
				// if nothing intersected put ambient color
				renderer.color = s_get_rgb(&prog->ambient_color);
			}
			mlx_my_putpixel(&(prog->mlx_config.img), renderer.win_x, renderer.win_y, renderer.color);
			renderer.win_y++;
		}
		renderer.win_x++;
	}
	printf("min_dist: %f\n",renderer.min_dist);
	printf("max_dist: %f\n",renderer.max_dist);
    return (SUCCESS);
}

// return 1 if intersection, 0 if not
int loop_test_object(t_prog *prog, t_interparam *param)
{
	t_list		*lst;
	t_object	*obj;
	int			ret;

	ret = 0;
	lst = prog->obj;
	while (lst)
	{
		obj = (t_object *)lst->content;
		if (obj->type >= 20)
		{
			ret = obj->test_intersection(obj->object, param);
		}
		lst = lst->next;
	}
	return (ret);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
