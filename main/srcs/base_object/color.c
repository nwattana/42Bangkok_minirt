#include "../../inc/minirt.h"


int     color_collect_string(char *color_string, t_color *color)
{
    char    **split_color;

    split_color = ft_split(color_string, ',');
    if (split_color == NULL)
        return (1);
    color->r = ft_atoi(split_color[0]);
    color->g = ft_atoi(split_color[1]);
    color->b = ft_atoi(split_color[2]);
    ft_free_split(split_color);
    return (0);
}

int     color_init(t_color *color, int r, int g, int b)
{
    color->r = r;
    color->g = g;
    color->b = b;
    return (0);
}

int     color_struct2int(t_color *color)
{
    return (color_rgb2int(color->r, color->g, color->b));
}

int     color_scale(t_color *res, double scale, t_color *a)
{
    res->r = (scale * (double)a->r);
    res->g = (scale * (double)a->g);
    res->b = (scale * (double)a->b);
    return (0);
}

