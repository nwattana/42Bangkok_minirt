#include "../../inc/minirt.h"

/// @brief Only collect color from string please check if the string is valid
int     collect_color(char *color_string, t_color *color)
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

int     assign_color(t_color *color, int r, int g, int b)
{
    color->r = r;
    color->g = g;
    color->b = b;
    color->value = create_rgb(r, g, b);
    return (0);
}

int     s_get_rgb(t_color *color)
{
    return (create_rgb(color->r, color->g, color->b));
}

int     color_copy(t_color *to, t_color *from)
{
    to->r = from->r;
    to->g = from->g;
    to->b = from->b;
    return (0);
}

int     color_scale(t_color *res, double scale, t_color *a)
{
    res->r = (scale * (double)a->r);
    res->g = (scale * (double)a->g);
    res->b = (scale * (double)a->b);
    if (res->r > 255)
        res->r = 255;
    if (res->g > 255)
        res->g = 255;
    if (res->b > 255)
        res->b = 255;
    return (0);
}

int     print_color(t_color *color)
{
    printf("color: %d, %d, %d\n", color->r, color->g, color->b);
    return (0);
}

int     color_add(t_color *res, t_color *a, t_color *b)
{
    res->r = a->r + b->r;
    if (res->r > 255)
        res->r = 255;
    res->g = a->g + b->g;
    if (res->g > 255)
        res->g = 255;
    res->b = a->b + b->b;
    if (res->b > 255)
        res->b = 255;
    return (0);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}