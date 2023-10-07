#include "../../inc/minirt.h"

int	re_render(t_prog *prog)
{
	t_mlx_confix *vars;

	render_image(prog);
	vars = &(prog->mlx_config);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);

	return (SUCCESS);
}