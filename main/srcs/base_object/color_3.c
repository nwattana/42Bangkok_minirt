#include "../../inc/minirt.h"

t_color int2color(int color)
{
    t_color res;

    res.r = (color >> 16) & 0xFF;
    res.g = (color >> 8) & 0xFF;
    res.b = color & 0xFF;
    return (res);
}

void    color_set_defval(t_color *color)
{
    color->r = 0;
    color->g = 0;
    color->b = 0;
}

int     color_dot(t_color *res, t_color *c1, t_color *intensity)
{
    res->r = (double)c1->r * (double)intensity->r;
    res->g = (double)c1->g * (double)intensity->g;
    res->b = (double)c1->b * (double)intensity->b;
}

