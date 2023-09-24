#include "../../inc/minirt.h"

/// @return 0 if on sucess, 1 if error
int render_image(t_prog *prog)
{
	int			win_x;
	int			win_y;
	int			color;
	t_ray 		ray;
	t_object 	*cam;
	t_color		color_obj;

	double		xfact;
	double		yfact;
	double		norm_x;
	double		norm_y;
	double 		min_dist;
	double 		max_dist;

	t_vec3d		local_normal;
	t_color		local_color;
	t_point3d	intersection_point;

	prog->p_state = RENDERING;

	min_dist = INFINITY;
	max_dist = -INFINITY;

	xfact = 1.0 / ((double)WINDOW_WIDTH / 2.0);
	yfact = 1.0 / ((double)WINDOW_HEIGHT / 2.0);
	

	// FIXME: change me
	t_object *obj_sphere;
	obj_sphere = (t_object *)get_object_from_list(prog->obj, SPHERE);

	int has_intersection = 0;

	cam = get_object_from_list(prog->obj, CAMERA);
	cam->print(cam->object);

	double min = 1.0f;
	double max = -1.0;
	win_x = 0;
	cam = get_object_from_list(prog->obj, CAMERA);
	while (win_x < WINDOW_WIDTH)
	{
		// normalize x
		norm_x = ((double)win_x * xfact) - 1.0f;
		win_y = 0;
		while (win_y < WINDOW_HEIGHT)
		{
			norm_y = ((double)win_y * yfact) - 1.0f;
			generate_ray(&ray, cam->object, norm_x, norm_y);
			// print_vec3d(&ray.origin);

			has_intersection = test_intersection(&ray, &intersection_point, &local_normal, &local_color);

			if (has_intersection)
			{
				double dist;
				t_vec3d temp;

				vec3d_minus(&temp, &intersection_point, &ray.origin);
				dist = vec3d_length(&temp);
				if (dist < min_dist)
					min_dist = dist;
				if (dist > max_dist)
					max_dist = dist;
				// gradient checking
				// if (((dist - 9.0) / 0.94605) > 1)
				// 	printf("dist: %f\n", (dist - 19.0) / 0.91492);
				color = create_rgb(255.0 - ((dist - 19.0) / 0.91492) * 255.0, 0, 0);
			}
			else
				color = create_rgb(0, 0, 0);
			mlx_my_putpixel(&(prog->mlx_config.img), win_x, win_y, color);
			win_y++;
		}
		// checkout normalize
		win_x++;
	}
	printf("min_dist: %f\n", min_dist);
	printf("max_dist: %f\n", max_dist);
    return (SUCCESS);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
