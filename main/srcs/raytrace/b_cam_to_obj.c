#include "../../inc/minirt.h"

// return color ที่จะเอาไป plot ที่ x,y
int which_color_should_be(t_prog *prog, int x, int y, t_renderer *renderer)
{
	t_light 		*light_obj;
	t_interparam 	param;
	int color;

	color = 0;
	light_obj = &prog->light;
	init_intersection_param(&param, prog);
	renderer->norm_x = ((double)x* renderer->xfact) - 1.0;
	renderer->norm_y = ((double)y * renderer->yfact) - 1.0;

	// หมุนกล้องไม่ได้
	generate_ray(&param.ray, &prog->camera, renderer->norm_x, renderer->norm_y);
	renderer->has_intersection = loop_test_object(prog, &param);

	if (renderer->has_intersection)
	{
		t_vec3d temp;

		temp = (t_vec3d){0,0,0};
		if (vec3d_eq(&param.local_normal, &temp))
		{
			printf("Error normal\n");
		}
		// ถ้า hit จะเข้าไปเชคแสงที่ วัตถุว่าโดนแสงแค่ไหน
		color = cal_light(prog, renderer, &param);
	}
	else
	{
		color = s_get_rgb(&prog->defval.color_purple);
	}
	return (color);
}

/// return is hit obj and edit interserction param via test_intersection of object
int loop_test_object(t_prog *prog, t_interparam *param)
{
	t_list		*lst;
	t_object	*obj;
	int			ret;
	int			test;

	ret = 0;
	test = 0;
	lst = prog->obj;
	while (lst)
	{
		obj = (t_object *)lst->content;
		if (obj == NULL)
		{
			debug_message("lst->content is null : loop_test_object");
			exit(1);
		}
		if (obj->type >= 20 )
		{
			test = obj->test_intersection(obj, param);
			if (test != 0)
			{
				ret = test;
				if (ret == 1 && param->intersection_obj == NULL)
				{
					param->intersection_obj = obj;
				}
			}
		}
		lst = lst->next;
	}
	return (ret);
}