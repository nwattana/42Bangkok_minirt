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
int     s_get_rgb(t_color *color);
int     assign_color(t_color *color, int r, int g, int b);
int     collect_color(char *color_string, t_color *color);

#endif