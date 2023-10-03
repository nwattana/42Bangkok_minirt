#include "../../inc/minirt.h"


int  init_renderer(t_renderer *ren, t_prog *prog)
{
	if (!ren)
		return (ERROR);
	ren->color = 0;
	ren->xfact = 1.0 / ((double)WINDOW_WIDTH / 2.0);
	ren->yfact = 1.0 / ((double)WINDOW_HEIGHT / 2.0);
	ren->min_dist = INFINITY;
	ren->max_dist = -INFINITY;
	ren->has_intersection = 0;


}

// INIT intersection paramert for each loop on x,y screen coordinate
int	init_intersection_param(t_interparam *param, t_prog *prog)
{
	// default value struct
	t_defval *defalt;

	if (!param)
	{
		debug_message("Intersection parameter is null");
		exit(ERROR);
	}
	defalt = &prog->defval;
	param->min_dist = INFINITY;
	param->intersection_obj = NULL;
	param->intensity = 0;

	return (SUCCESS);
}
