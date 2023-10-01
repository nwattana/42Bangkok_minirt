#ifndef COLOR_H
# define COLOR_H
# include "minirt.h"

typedef struct s_color
{
    int	r;
    int	g;
    int	b;
}	t_color;

int	    create_rgb(int r, int g, int b);
int     get_rgb(t_color *color);
int     color_assign(t_color *color, int r, int g, int b);
int     collect_color(char *color_string, t_color *color);

int     color_copy(t_color *to, t_color *from);

int     color_scale(t_color *res, double scale, t_color *a);
int     print_color(t_color *color);
int     color_add(t_color *res, t_color *a, t_color *b);

#endif