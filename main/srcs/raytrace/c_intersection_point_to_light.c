#include "../../inc/minirt.h"


// ต้อง return color ที่จะเอาไป plot ที่ x,y
// เรียก เมื่อ hit object เท่านั้น
int	cal_light(t_prog *prog, t_renderer *renderer, t_interparam *param)
{
	int			valid_light;
    int         ret_color;
    t_color     light_scaled;
    t_light     *light_obj;

    light_obj = &prog->light;
    valid_light = 0;
    ret_color = 0;

    if (param->intersection_obj == NULL)
    {
        debug_message("param->intersection_obj is null : cal_light");
        exit(1);
    }
	valid_light = point_light(&prog->light, param, prog);
	if (valid_light)
	{
        color_copy(&light_scaled, &light_obj->color);
        color_scale(&light_scaled, param->intensity, &light_scaled);
        color_add(&light_scaled, &param->local_color, &light_scaled);
        ret_color = s_get_rgb(&light_scaled);
    }
    else
    {
        t_ambient   *ambient;
        t_color  ambient_color;

        ambient = &prog->ambient;
        color_copy(&ambient_color, &ambient->color);
        color_scale(&ambient_color, ambient->intensity, &ambient_color);

        color_copy(&light_scaled, &param->local_color);
        color_scale(&light_scaled, ambient->intensity, &light_scaled);
        ret_color = s_get_rgb(&light_scaled);
    }
    return (ret_color);
}

int vec3d_eq(t_vec3d *v1, t_vec3d *v2)
{
    if ((v1->x == v2->x) && (v1->y == v2->y) && (v1->z == v2->z))
    {
        return (SUCCESS);
    }
    return (ERROR);
}

int point_light(t_light *light, t_interparam *param, t_prog *prog)
{
    t_vec3d         light_dir;
    t_point3d       light_start;
    t_ray           inter_to_light;
    t_interparam    light_param;
    double angle;
    int reach_ray;

    reach_ray = 0;
    init_light_intersection_param(&light_param, prog, param);
    if (vec3d_eq(&param->intersection_point, &light->position))
    {
        param->intensity = 0;
        return (1);
    }
    create_ray_from_points(&inter_to_light, &param->intersection_point, &light->position);
    reach_ray = loop_test_light(prog, &light_param, &inter_to_light);

    // ยิง แสงจาก intersection point ไป หา light source

    vec3d_minus(&light_dir, &light->position, &param->intersection_point);
    // DEBUG normalize
    if (vec3d_length(&light_dir) == 0)
    {
        debug_message("light_dir length is 0: point_light");
        return (0);
    }
    vec3d_normalize(&light_dir);
    if (vec3d_normalize(&light_dir) == 1)
    {
        printf("c_inter1\n");
    }
      
    vec3d_assign(&light_start, &param->intersection_point);
    angle = acos(vec3d_dot(&param->local_normal, &light_dir));
    if (angle >= 1.5708 || reach_ray)
    {
        param->intensity = 0;
        return (0);
    }
    param->intensity = light->intensity * (1.0 - (angle / 1.5708));
    return (1);
}

int loop_test_light(t_prog *prog, t_interparam *param, t_ray *inter_to_light)
{
    t_list      *lst;
    t_object    *obj;
    int         ret;
    int         test;

    ret = 0;
    test = 0;
    lst = prog->obj;

    while (lst)
    {
        obj = (t_object *)lst->content;
        if (lst->content == NULL)
        {
            debug_message("lst->content is null");
            exit(1);
        }
        if (param->intersection_obj == NULL)
        {
            return (ERROR);
        }
        if (obj->type >= 20 && obj->id != param->intersection_obj->id)
        {
            // test distance for each object in intersection
            test = obj->test_intersection(obj , param);
            if (test != 0)
                return (1);
        }
        lst = lst->next;
    }
    return (0);
}


void  init_light_intersection_param(t_interparam *param, t_prog *prog, t_interparam *inter)
{
	param->min_dist = INFINITY;
    if (inter->intersection_obj == NULL)
    {
        debug_message("inter->intersection_obj is null");
        exit(1);
    }
	param->intersection_obj = inter->intersection_obj;
	param->intensity = 0;
}