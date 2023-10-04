#include "../inc/minirt.h"
int     render_image(t_prog *prog);
void    generate_ray(t_ray *ray, t_prog *prog, int x, int y);
int     ray_color(t_ray *ray, t_prog *prog);
void    print_ray(t_ray *ray, char *mess);

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
            // color = color_rgb2int(255 * (WINDOW_WIDTH - x) * (WINDOW_HEIGHT - y )/ (WINDOW_WIDTH * WINDOW_HEIGHT), 0, 0);
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
        color = (t_color){255,0,0};
    }
    else
    {
        color = (t_color){0,0,0};
    }

    return (color_struct2int(&color));
}

int     trace_ray_to_obj(t_prog *prog, t_interparam *param)
{
    t_list      *lst;
    t_object    *obj;
    int hit;

    lst = prog->obj;
    while (lst)
    {
        obj = (t_object *)lst->content;
        if (obj->type == SPHERE)
            hit = sp_test_intersection(obj->object, param);
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
}