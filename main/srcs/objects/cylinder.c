#include "../../inc/minirt.h"

void    print_cylinder(void *object)
{
    t_cylinder *cylinder;

    cylinder = (t_cylinder *)object;
    printf("cylinder: \n");
    print_vec3d(&cylinder->point,"point: ");
    print_vec3d(&cylinder->normal,"normal: ");
    printf("radi: %f\n", cylinder->radi);
    printf("height: %f\n", cylinder->len);
    print_color(&cylinder->color);
}

void    clean_cylinder(void *object)
{
    t_cylinder *cylinder;

    cylinder = (t_cylinder *)object;
    free(cylinder);
}

int     cy_test_intersection(void *object, t_interparam *p)
{
    t_cylinder      *cy;
    t_object        *obj;
    t_ray           ray[3];
    t_interparam    mox[3];

    obj = (t_object *)object;
    cy = (t_cylinder *)obj->object;

    create_mox_inters(ray, mox, p);

    if (cy_rear(cy, &mox[0]))
    {
        set_inters_from_mox(p, &mox[0]);
        return (1);
    }
    if (cy_cap(cy, &mox[1]))
    {
        set_inters_from_mox(p, &mox[1]);
        return (1);
    }
    return (0);
}

void create_mox_inters(t_ray *ray, t_interparam *mox, t_interparam *p)
{
    int i;

    i = 0;
    while (i < 3)
    {
        ft_memcpy(&mox[i], p, sizeof(t_interparam));
        ft_memcpy(&ray[i], p->ray, sizeof(t_ray));
        mox[i].ray = &ray[i];
        i++;
    }
}

int cy_rear(t_cylinder *cy, t_interparam *p)
{
    double dist;
    t_vec3d ints2point;

    dist = cy_cale_dist(p->ray, cy);
    if (dist > 0.0)
    {
        cy_intersection_point(&p->f_point, p->ray, dist);
        cy_intersection_normal(&p->f_normal, &p->f_point, &cy->point);
        vec3d_minus(&ints2point, &p->f_point, &cy->point);
        if (fabs(vec3d_dot(&ints2point, &cy->normal)) < cy->len / 2.0)
        {
            p->f_dist = dist;
            p->f_ishit = 1;
            ft_memcpy(&p->f_color, &cy->color, sizeof(t_color));
            return (1);
        }
    }
    return (0);
}

int set_inters_from_mox(t_interparam *p, t_interparam *mox)
{
    p->f_dist = mox->f_dist;
    p->f_ishit = mox->f_ishit;
    ft_memcpy(&p->f_color, &mox->f_color, sizeof(t_color));
    ft_memcpy(&p->f_point, &mox->f_point, sizeof(t_point3d));
    ft_memcpy(&p->f_normal, &mox->f_normal, sizeof(t_vec3d));
    return (SUCCESS);
}

int cy_cap(t_cylinder *cy, t_interparam *p)
{
    t_vec3d     inters2center;
    t_plane    pl[2];

    cy_create_plane(pl, cy);
    if (pl_sub_intersect(&pl[0], p))
    {
        vec3d_minus(&inters2center, &p->f_point, &pl[0].point);
        if (vec3d_length(&inters2center) < cy->radi)
        {
            p->f_dist = p->f_dist;
            p->f_ishit = 1;
            ft_memcpy(&p->f_color, &cy->color, sizeof(t_color));
            return (1);
        }
    }
    if (pl_sub_intersect(&pl[1], p))
    {
        vec3d_minus(&inters2center, &p->f_point, &pl[1].point);
        if (vec3d_length(&inters2center) < cy->radi)
        {
            p->f_dist = p->f_dist;
            p->f_ishit = 1;
            ft_memcpy(&p->f_color, &cy->color, sizeof(t_color));
            return (1);
        }
    }
    return (0);
}

int cy_intersection_normal(t_vec3d *normal, t_point3d *inters, t_point3d *center)
{
    vec3d_minus(normal, inters, center);
    if(vec3d_normalize(normal))
    {
        debug_message("cyhere intersection_normal: normal is zero vector\n");
        return (ERROR);
    }
    return (SUCCESS);
}

int cy_intersection_point(t_vec3d *inters, t_ray *ray, double dist)
{
    t_vec3d *v3;

    vec3d_scale(inters, dist, &ray->direction);
    vec3d_plus(inters, &ray->origin, inters);
    if (vec3d_length(inters) == 0.0)
    {
        debug_message("cyhere intersection_point: inters is zero vector\n");
        return (ERROR);
    }
    return (SUCCESS);
}

double  cy_cale_dist(t_ray *ray, t_cylinder *cy)
{
    double  a;
    double  b;
    double  c;
    t_vec3d cam2obj;
    double  dist;

    vec3d_minus(&cam2obj, &ray->origin, &cy->point);
    a = vec3d_dot(&ray->direction, &ray->direction) - pow(vec3d_dot(&ray->direction, &cy->normal), 2);
    b = 2.0 * (vec3d_dot(&cam2obj, &ray->direction) - vec3d_dot(&ray->direction, &cy->normal) * vec3d_dot(&cam2obj, &cy->normal));
    c = vec3d_dot(&cam2obj, &cam2obj) - pow(vec3d_dot(&cam2obj, &cy->normal), 2) - (cy->radi * cy->radi);

    return(solve_quadratic(a, b, c));
}

int cy_create_plane(t_plane *pl, t_cylinder *cy)
{
    t_vec3d     cale_temp;
    t_point3d   temp;

    vec3d_scale(&cale_temp, cy->len / 2.0, &cy->normal);
    vec3d_plus(&temp, &cy->point, &cale_temp);
    ft_memcpy(&pl[0].color, &cy->color, sizeof(t_color));
    ft_memcpy(&pl[0].point, &temp, sizeof(t_point3d));
    ft_memcpy(&pl[0].normal, &cy->normal, sizeof(t_vec3d));
    vec3d_scale(&cale_temp, -cy->len / 2.0, &cy->normal);
    vec3d_plus(&temp, &cy->point, &cale_temp);
    ft_memcpy(&pl[1].color, &cy->color, sizeof(t_color));
    ft_memcpy(&pl[1].point, &temp, sizeof(t_point3d));
    vec3d_scale(&cale_temp, -1, &cy->normal);
    ft_memcpy(&pl[1].normal, &cale_temp, sizeof(t_vec3d));
    return (SUCCESS);
}

void print_inters_param(t_interparam *p)
{
    print_ray(p->ray, "ray: ");
    printf("inters_param: \n");
    print_vec3d(&p->f_point, "f_point: ");
    print_vec3d(&p->f_normal, "f_normal: ");
    printf("f_dist: %f\n", p->f_dist);
    print_color(&p->f_color);
    printf("f_ishit: %d\n", p->f_ishit);
}