#include "../inc/minirt.h"

t_prog *render_scene(t_prog *prog);

void debug_mlx_status(t_mlx_confix *vars)
{
    printf("is_initmlx: %d\n", vars->is_initmlx);
    printf("is_initwin: %d\n", vars->is_initwin);
    printf("is_init_img: %d\n", vars->is_init_img);
}

void terror(char *str)
{
    ft_putstr_fd(str, 2);
    exit(1);
}

void    init_prog(t_prog *prog)
{
    prog->mlx.is_init_img = 0;
    prog->mlx.is_initwin = 0;
    prog->mlx.is_initmlx = 0;
}

int	main(int argc, char **argv)
{
    t_camera camera = {{0, 0, 0}, {0, 0, 1}, 90};
    t_prog  prog;
    t_mlx_confix *vars;

    vars = &prog.mlx;
    init_prog(&prog);
    init_my_mlx(&prog.mlx);

    // scene 
    render_scene(&prog);

    debug_monitor_value(&vars->monitor);

    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);

    // mlx loop hook set here when nothing to think
    mlx_my_loop(&prog);
    return (0);
}


void    coor_screen_to_cam(t_monitor_coord *cam, t_monitor *monitor, double x, double y, double fov)
{
    cam->x = (2 * (x + 0.5) / WINDOW_WIDTH) * monitor->fov * monitor->aspect_ratio;
    cam->y = (1 - 2 * ((y + 0.5) / WINDOW_HEIGHT));
}


t_prog *render_scene(t_prog *prog)
{
    int pixel_screen_x;
    int pixel_screen_y;
    double r, g, b;
    t_mlx_confix *vars;

    vars = &prog->mlx;
    pixel_screen_y = 0;
    while(pixel_screen_y < WINDOW_HEIGHT)
    {
        pixel_screen_x = 0;
        while(pixel_screen_x < WINDOW_WIDTH)
        {
            r = (double)pixel_screen_x / WINDOW_WIDTH * 255.0;
            b = (double)pixel_screen_y / WINDOW_HEIGHT * 255.0;
            mlx_my_putpixel(&vars->img, pixel_screen_x, pixel_screen_y, create_rgb(r,b,0));
            pixel_screen_x++;
        }
        pixel_screen_y++;
    }
    return (prog);
}