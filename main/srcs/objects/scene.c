#include "../../inc/minirt.h"

int		ray_color(t_ray *ray, t_prog *prog);
int select_color(int x, int y, t_prog *prog);
int	hit_sphere(t_prog *prog, t_ray *ray);
int simple_gradient(int x, int y)
{
	return (create_rgb((double)x/WINDOW_WIDTH * 255, (double)y/WINDOW_HEIGHT * 255, 255/4));
}

/// @return 0 if on sucess, 1 if error
int render_image(t_prog *prog)
{
	int color;
	int x;
	int y;

	prog->p_state = RENDERING;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = WINDOW_HEIGHT;
		while (y > 0)
		{
			color = select_color(x, y, prog);
			mlx_my_putpixel(&(prog->mlx_config.img), x, y, color);
			y--;
		}
		x++;
	}
    return (SUCCESS);
}


int select_color(int x, int y, t_prog *prog)
{
	double		u;
	double		v;
	t_ray 		ray;
	t_camera	*cam;

	cam = prog->camera;
	if (!cam)
	{
		debug_message("No camera found");
		exit(1);
	}
	u = x / (double)WINDOW_WIDTH - 1; 
	v = y / (double)WINDOW_HEIGHT - 1;
	create_ray(&ray, cam, u, v);
	return (ray_color(&ray, prog));
}

int		ray_color(t_ray *ray, t_prog *prog)
{
	double va;
	t_color temp;
	t_color temp2;

	if (hit_sphere(prog, ray))
		return (create_rgb(255, 0, 0));
	
	va = 0.5 * (ray->direction.y + 1.0);
	color_assign(&temp, 255, 255, 255);
	color_assign(&temp2, 0.5*255, 0.7*255, 255);

	color_scale(&temp, 1.0 - va, &temp);
	color_scale(&temp2, va, &temp2);
	color_add(&temp, &temp2, &temp);

	return (create_rgb(temp.r, temp.g, temp.b));
}

int	hit_sphere(t_prog *prog, t_ray *ray)
{
	t_vec3d *oc;
	t_sphere *sp;

	double a;
	double b;
	double c;
	double discriminant;

	sp = ((t_object *)(get_object_from_list(prog->obj, SPHERE)))->object;

	a = vec3d_dot(&ray->direction, &ray->direction);
	b = 2.0  * vec3d_dot(&ray->direction, oc);
	c = vec3d_dot(oc, oc) -  sp->radius * sp->radius;
	discriminant = b * b - 4 * a * c;
	// printf("discriminant: %f, %f, %f, %f\n", discriminant, a, b, c);

	return (discriminant > 0);
}
