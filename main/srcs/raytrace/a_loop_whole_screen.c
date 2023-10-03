#include "../../inc/minirt.h"

/// @return 0 if on sucess, 1 if error
int render_image(t_prog *prog)
{
	t_renderer renderer;
	int x;
	int y;
	int	color;

	init_renderer(&renderer, prog);
	prog->p_state = RENDERING;
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			color = which_color_should_be(prog, x, y, &renderer);
			mlx_my_putpixel(&(prog->mlx_config.img), x, y, color);
			y++;
		}
		x++;
	}
    return (SUCCESS);
}
