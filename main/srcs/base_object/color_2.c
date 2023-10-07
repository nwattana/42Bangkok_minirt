#include "../../inc/minirt.h"

int     print_color(t_color *color)
{
    printf("color: [%d, %d, %d]\n", color->r, color->g, color->b);
    return (0);
}

int     color_plus(t_color *res, t_color *a, t_color *b)
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

int	color_rgb2int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int color_copy(t_color *dst, t_color *src)
{
    dst->r = src->r;
    dst->g = src->g;
    dst->b = src->b;
    return (0);
}

