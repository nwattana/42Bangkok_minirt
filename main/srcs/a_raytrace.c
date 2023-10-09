#include "../inc/minirt.h"

int render_image(t_prog *prog)
{
    t_ray   ray;
    int     color;    

    prog->x = 0;
    while (prog->x < WINDOW_WIDTH)
    {
        prog->y = 0;
        while (prog->y < WINDOW_HEIGHT)
        {
            generate_ray(&ray, prog, prog->x, prog->y);
            color = ray_color(&ray, prog);
            mlx_my_putpixel(&prog->mlx_config.img, prog->x, prog->y, color);
            prog->y++;
        }
        prog->x++;
    }
	return (SUCCESS);
}

void    generate_ray(t_ray *ray, t_prog *prog, int x, int y)
{
    t_camera *cam;

    cam = (t_camera *)&prog->camera;
    ray->direction.x = x * cam->u.x + y * cam->v.x + cam->top_left.x;
    ray->direction.y = x * cam->u.y + y * cam->v.y + cam->top_left.y;
    ray->direction.z = x * cam->u.z + y * cam->v.z + cam->top_left.z;
    vec3d_normalize(&ray->direction);
    vec3d_assign(&ray->origin, &cam->position);
}

int     ray_color(t_ray *ray, t_prog *prog)
{
    t_color         color;
    t_interparam    param;
    int     hit;

    color = (t_color){0,0,0};
    param.ray = ray;
    init_intersection_param(prog, ray, &param);
    hit = trace_ray_to_obj(prog, &param);
    if (hit)
    {
        trace_light(prog, &param);
    }
    ft_memcpy(&color, &param.final_color, sizeof(t_color));

    return (color_struct2int(&color));
}

int     cale_angle_scale(t_obslight *l_param, t_interparam *p)
{
    l_param->angle = acos(vec3d_dot(&p->inters_normal, &l_param->light_dir));
    if (l_param->angle <= 1.570796)
    {
        l_param->angle_scale = (1.0 - (l_param->angle / 1.570796));
    }
    else
    {
        l_param->angle_scale = 0;
    }
	return (SUCCESS);
}
