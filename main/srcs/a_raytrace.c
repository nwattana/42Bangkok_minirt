#include "../inc/minirt.h"
typedef struct s_obslight
{
    t_vec3d     light_dir;
    double      angle;
    double      max_dist;
    double      angle_scale;
}       t_obslight;

int     render_image(t_prog *prog);
void    generate_ray(t_ray *ray, t_prog *prog, int x, int y);
int     ray_color(t_ray *ray, t_prog *prog);
void    print_ray(t_ray *ray, char *mess);
void    init_intersection_light_param(t_prog *prog, t_interparam *param, t_obslight *light_param);
int     trace_inters_to_light(t_prog *prog, t_interparam *param);
void    trace_light(t_prog *prog, t_interparam *param);

int render_image(t_prog *prog)
{
    int x;
    int y;    

    x = 0;
    while (x < WINDOW_WIDTH)
    {
        y = 0;
        while (y < WINDOW_HEIGHT)
        {
            t_ray ray;
            int color;
            t_color colors;

            generate_ray(&ray, prog, x, y);
            color = ray_color(&ray, prog);
            mlx_my_putpixel(&prog->mlx_config.img, x, y, color);
            y++;
        }
        x++;
    }
}


void    print_ray(t_ray *ray, char *mess)
{
    printf("ray %s:\n", mess);
    print_vec3d(&ray->origin, "origin");
    print_vec3d(&ray->direction, "direction");
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
        ft_memcpy(&color, &param.local_color, sizeof(t_color));
    }
    else
    {

        ft_memcpy(&color, &prog->ambient_color, sizeof(t_color));
    }
    return (color_struct2int(&color));
}

void    trace_light(t_prog *prog, t_interparam *param)
{
    int         hit;
    t_obslight  light_param;
    t_color     cale_color;

    hit = 0;
    init_intersection_light_param(prog, param, &light_param);
    hit = trace_inters_to_light(prog, param);
    if (hit)
    {
        color_scale(&cale_color, prog->ambient_intensity, &param->local_color);
        color_plus(&param->local_color, &param->local_color, &cale_color);
    }
    else
    {
        color_scale(&cale_color, prog->ambient_intensity, &param->local_color);
        color_plus(&param->local_color, &param->local_color, &cale_color);
        color_scale(&param->local_color, light_param.angle_scale, &param->local_color);
    }
    // color_scale(&cale_color, prog->ambient_intensity, &cale_color);
}


void    init_intersection_light_param(t_prog *prog, t_interparam *param, t_obslight *light_param)
{
    light_param->angle = 0;

    vec3d_minus(&light_param->light_dir, &prog->light.position, &param->inters_point);
    light_param->max_dist = vec3d_length(&light_param->light_dir);
    vec3d_normalize(&light_param->light_dir);

    light_param->angle = acos(vec3d_dot(&param->inters_normal, &light_param->light_dir));
    if (light_param->angle <= 1.570796)
    {
        light_param->angle_scale = (1.0 - (light_param->angle / 1.570796));
    }
    else
    {
        print_vec3d(&param->inters_normal, "inters_normal");
        light_param->angle_scale = prog->ambient_intensity;
    }
}

int     trace_inters_to_light(t_prog *prog, t_interparam *param)
{
    t_list      *lst;
    t_object    *obj;
    int         temp;

    lst = prog->obj;
    temp = 0;
    while (lst && !temp)
    {
        obj = (t_object *)lst->content;
        if (obj->id == param->inter_obj_id)
        {
            lst = lst->next;
            continue;
        }
        if (obj->type == SPHERE)
        {
            temp = sp_test_intersection(obj, param);
        }
        lst = lst->next;
    }
    return (temp);
}

// NOTE not complete
int     trace_ray_to_obj(t_prog *prog, t_interparam *param)
{
    t_list      *lst;
    t_object    *obj;
    int hit;
    int temp;

    hit = 0;
    lst = prog->obj;
    while (lst)
    {
        obj = (t_object *)lst->content;
        if (obj->type == SPHERE)
        {
            temp = sp_test_intersection(obj, param);
            if (temp == 1)
            {
                hit = temp;
            }
        }
        else if (obj->type == PLANE)
        {
            temp = pl_test_intersection(obj, param);
            if (temp == 1)
            {
                hit = temp;
            }
        }
        lst = lst->next;
    }
    return (hit);
}

int init_intersection_param(t_prog *prog, t_ray *ray, t_interparam *param)
{
    t_vec3d     vec;

    vec3d_init(&param->inters_normal, 0,0,0);
    vec3d_init(&param->inters_point, 0,0,0);
    param->min_dist = INFINITY;
    param->is_hit = 0;
    param->inter_obj_id = -1;
    param->local_color = (t_color){0,0,0};
}