#include "../../inc/minirt.h"

/// @return 0 if on sucess, 1 if error
int render_image(t_prog *prog)
{
	int		win_x;
	int		win_y;
	int		color;
    int     r;
    int     g;

	win_x = 0;
	while (win_x < WINDOW_WIDTH)
	{
		win_y = 0;
		while (win_y < WINDOW_HEIGHT)
		{
			// all render logic here
            r = ((double)win_x / (double)WINDOW_WIDTH) * 255.0;
	        g = ((double)win_y / (double)WINDOW_HEIGHT) * 255.0;
	        color = create_rgb(r, g, 0);

			// mlx_my_putpixel(&(prog->mlx_config.img), win_x, win_y, color);
			win_y++;
		}
		win_x++;
	}
    return (SUCCESS);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
