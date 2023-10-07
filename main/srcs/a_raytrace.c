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

void    trace_light(t_prog *prog, t_interparam *param)
{
    t_obslight  l_param;

    init_inters_light_param(prog, param, &l_param);
    if (param == NULL)
    {
        printf("trace_light: param is NULL\n");
        exit(0);
    }
    trace_inters_to_light(prog, param, &l_param);
    if (l_param.stuck == 0)
    {
        cale_angle_scale(&l_param, param);
    }
    color_scale(&l_param.light.light_color, l_param.angle_scale, &param->inters_color);
    color_scale(&l_param.light.ambient_color, prog->ambient_intensity, &param->inters_color);
    color_plus(&param->final_color, &l_param.light.ambient_color, &l_param.light.light_color);
}

void    init_inters_light_param(t_prog *prog, t_interparam *param, t_obslight *light_param)
{
    color_set_defval(&light_param->light.light_color);
    color_set_defval(&light_param->light.ambient_color);
    light_param->scale_angle = 0;
    light_param->angle = 0;
    vec3d_minus(&light_param->light_dir, &prog->light.position, &param->inters_point);
    light_param->max_dist = vec3d_length(&light_param->light_dir);
    vec3d_normalize(&light_param->light_dir);
    light_param->stuck = 0;
    vec3d_assign(&light_param->ray.origin, &param->inters_point);
    vec3d_assign(&light_param->ray.direction, &light_param->light_dir);
    param->ray = &light_param->ray;
}

int     trace_inters_to_light(t_prog *prog, t_interparam *param, t_obslight *light_param)
{
    t_list      *lst;
    t_object    *obj;
    int         temp;

    lst = prog->obj;
    temp = 0;
    while (lst && !temp)
    {
        reset_inters_focus(param);
        obj = (t_object *)lst->content;
        if (obj->id == param->inters_obj_id)
        {
            lst = lst->next;
            continue;
        }
        if (obj->type == SPHERE)
        {
            temp = sp_test_intersection(obj, param);
        }
        else if (obj->type == PLANE)
        {
            temp = pl_test_intersection(obj, param);
        }
        else if (obj->type == CYLINDER)
        {
            temp = cy_test_intersection(obj, param);
        }
        lst = lst->next;
    }
    if (param->f_dist < light_param->max_dist - 0.001)
        light_param->stuck = 1;
    return (temp);
}

int     trace_ray_to_obj(t_prog *prog, t_interparam *param)
{
    t_list      *lst;
    t_object    *focus_obj;
    int         f_hit;

    lst = prog->obj;
    while (lst)
    {
        // reset focus param
        reset_inters_focus(param);
        focus_obj = (t_object *)lst->content;
        if (focus_obj->type == SPHERE)
        {
            f_hit = sp_test_intersection(focus_obj, param);
        }
        else if (focus_obj->type == PLANE)
        {
            f_hit = pl_test_intersection(focus_obj, param);
        }
        else if (focus_obj->type == CYLINDER)
        {
            f_hit = cy_test_intersection(focus_obj, param);
        }
        if (param->f_ishit == 1)
        {
            if (param->f_dist < param->inters_dist)
            {
                gather_inters_info(param, focus_obj);
            }
        }
        lst = lst->next;
    }
    return (param->hit);
}

int gather_inters_info(t_interparam *param, t_object *focus_obj)
{
    param->inters_dist = param->f_dist;
    ft_memcpy(&param->inters_point, &param->f_point, sizeof(t_vec3d));
    ft_memcpy(&param->inters_normal, &param->f_normal, sizeof(t_vec3d));
    ft_memcpy(&param->inters_color, &param->f_color, sizeof(t_color));
    param->inters_obj_id = focus_obj->id;
    param->d_inters_obj_type = focus_obj->type;
	return (SUCCESS);
}

int init_intersection_param(t_prog *prog, t_ray *ray, t_interparam *param)
{
	(void)prog;
	(void)ray;
    reset_inters_focus(param);
    vec3d_init(&param->inters_normal, 0,0,0);
    vec3d_init(&param->inters_point, 0,0,0);
    param->inters_dist = INFINITY;
    param->f_ishit = 0;
    param->inters_obj_id = -1;
    param->inters_color = (t_color){0,0,0};
    param->start_ray_obj_id = CAMERA_ID;
    param->hit = 1;
	return (SUCCESS);
}

int reset_inters_focus(t_interparam *param)
{
    param->f_dist = INFINITY;
    param->f_ishit = 0;
    param->f_color = (t_color){0,0,0};
    return (SUCCESS);
}

void    print_obj_type(int type)
{
    if (type == SPHERE)
        printf("SPHERE");
    else if (type == PLANE)
        printf("PLANE");
    else if (type == CYLINDER)
        printf("CYLINDER");
}